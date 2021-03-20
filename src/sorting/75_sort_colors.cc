#include "sorting.hh"
#include <algorithm>
using namespace std;

class Solution
{
public:
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

    void sortColors(vector<int>& nums) {
        //std::sort(nums.begin(), nums.end());
        quick_sort(nums, 0, (int)nums.size() - 1);
    }
};

void run_sort_colors_75()
{
    Solution solution;
    vector<int> v = {2, 1, 2};
    print_int_vector(v);
    solution.sortColors(v);
    print_int_vector(v);
}
