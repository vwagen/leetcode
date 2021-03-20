#include "sorting.hh"
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int target = 0, size1 = nums1.size(), size2 = nums2.size();
        size_t mid_lower = (size1 + size2 - 1) / 2;
        size_t mid_upper = (size1 + size2 - 1) / 2 + (size1 + size2 - 1) % 2;
        for (int i = 0, j = 0, cnt = 0; i < size1 || j < size2;)
        {
            vector<int>* p_nums;
            int* p_index;
            if (i >= size1)
            {
                p_nums = &nums2;
                p_index = &j;
            }
            else if (j >= size2 || nums1[i] < nums2[j])
            {
                p_nums = &nums1;
                p_index = &i;
            }
            else
            {
                p_nums = &nums2;
                p_index = &j;
            }

            if (cnt >= mid_lower && cnt <= mid_upper)
            {
                target += (*p_nums)[*p_index];
            }
            else if (cnt > mid_upper)
            {
                break;
            }
            (*p_index)++;
            cnt++;
        }
        return mid_lower < mid_upper ? (double)target / 2.0: (double)target;
    }
};

void run_median_of_two_sorted_arrays_4()
{
    Solution solution;
    vector<int> v1 = {1, 2, 3, 7};
    vector<int> v2 = {2, 4, 8};
    double ret = solution.findMedianSortedArrays(v1, v2);
    printf("ret: %f\n", ret);
}
