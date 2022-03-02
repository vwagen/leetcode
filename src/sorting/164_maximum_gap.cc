#include "utils.hh"
#include <algorithm>
using namespace std;

class Solution
{
public:
    /* Time complexity: O(nlogn). Space complexity: O(1). */
    void quick_sort(vector<int>& nums, int start, int end)
    {
        if (start >= end) return;
        int l = start, r = end, delta = 1;
        int *p_moved = &l, *p_fixed = &r;
        while (l < r)
        {
            if ((delta > 0 && nums[*p_moved] >= nums[*p_fixed])
                || (delta < 0 && nums[*p_fixed] >= nums[*p_moved]))
            {
                std::swap(nums[*p_moved], nums[*p_fixed]);
                std::swap(p_moved, p_fixed);
                delta *= -1;
            }
            *p_moved += delta;
        }
        quick_sort(nums, start, l - 1);
        quick_sort(nums, l + 1, end);
    }

    /* Time complexity: O(N*M). Space complexity: O(N). */
    void radix_sort(vector<int>& nums)
    {
        if (nums.size() < 2)
        {
            return;
        }

        auto my_pow = [](int base, int times)
        {
            long long origin = 1;
            for (int i = 0; i < times; i++)
            {
                origin *= base;
            }
            return origin;
        };

        int max = nums[0];
        for (int i : nums)
        {
            max = max >= i ? max : i;
        }

        int magnitude = (int)round(log10(max));
        vector<int> buckets[10];
        for (int k = 0; k <= magnitude; k++)
        {
            for (int i : nums)
            {
                buckets[((long long)i % my_pow(10, k + 1)) / my_pow(10, k)].push_back(i);
            }
            nums.clear();
            for (int m = 0; m < 10; m++)
            {
                for (int i : buckets[m])
                {
                    nums.push_back(i);
                }
                buckets[m].clear();
            }
        }
    }

    int maximumGap(vector<int>& nums) {
        //quick_sort(nums, 0, (int)nums.size() - 1);
        radix_sort(nums);
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            result = nums[i] - nums[i - 1] > result ? nums[i] - nums[i - 1] : result;
        }
        return result;
    }
};

int main(int argc,char *argv[])
{
    Solution solution;
    vector<int> v = {1,10000000};
    print_int_vector(v);
    int gap = solution.maximumGap(v);
    printf("Maximum gap: %d\n", gap);

    fflush(stdout);
    return 0;
}
