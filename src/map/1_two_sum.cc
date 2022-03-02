#include "utils.hh"
using namespace std;

static void qsort(vector<int>& nums, vector<int>& indices, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int low_t = low;
    int high_t = high;

    int pivot_index = high;
    while (low < high)
    {
        while (low < high && nums[low] <= nums[high])
        {
            low++;
        }
        std::swap(nums[low], nums[high]);
        std::swap(indices[low], indices[high]);
        pivot_index = low;
        high--;
        if (low >= high)
        {
            break;
        }
        while (low < high && nums[low] <= nums[high])
        {
            high--;
        }
        std::swap(nums[low], nums[high]);
        std::swap(indices[low], indices[high]);
        low++;
        pivot_index = high;
    }

    qsort(nums, indices, low_t, pivot_index - 1);
    qsort(nums, indices, pivot_index + 1, high_t);
}
static vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> indices;
    for (int i = 0; i < nums.size(); i++)
    {
        indices.push_back(i);
    }

    qsort(nums, indices, 0, nums.size() - 1);
    print_int_vector(nums);
    print_int_vector(indices);

    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        if (nums[low] + nums[high] > target)
        {
            high--;
        }
        else if (nums[low] + nums[high] < target)
        {
            low++;
        }
        else
        {
            break;
        }
    }

    //printf("%d   %d\n", low, high);
    //printf("%d   %d\n", nums[low], nums[high]);
    vector<int> ret = {indices[low], indices[high]};
    return ret;
}

static vector<int> twoSum_best(vector<int>& nums, int target)
{
    vector<int> ret;
    std::unordered_map<int, int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        if (v.find(nums[i]) != v.end())
        {
            ret.push_back(i);
            ret.push_back(v[nums[i]]);
            break;
        }
        //printf("%d    %d\n", target - nums[i], i);
        v[target - nums[i]] = i;
    }
    return ret;
}

int main(int argc,char *argv[])
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    auto ret = twoSum_best(nums, target);
    //auto ret = twoSum(nums, target);
    printf("\n[");
    for (auto& i : ret)
    {
        printf("%d,", i);
    }
    printf("]\n");

    fflush(stdout);
    return 0;
}