#include "utils.hh"
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval) {
        int begin = 0, end = intervals.size() - 1;
        int mid = (end - begin) / 2 + begin;
        while (begin <= end)
        {
            mid = (end - begin) / 2 + begin;
            if (intervals[mid][1] < new_interval[0])
            {
                begin = mid + 1;
            }
            else if (intervals[mid][0] > new_interval[1])
            {
                end = mid - 1;
            }
            else
            {
                break;
            }
        }
        if (intervals.empty())
        {
            intervals.push_back(new_interval);
        }
        else if (intervals[mid][1] < new_interval[0])
        {
            intervals.insert(intervals.begin() + mid + 1, new_interval);
        }
        else if (intervals[mid][0] > new_interval[1])
        {
            intervals.insert(intervals.begin() + mid, new_interval);
        }
        else
        {
            int left = mid;
            int right = mid;
            while (left > 0 && intervals[left - 1][1] >= new_interval[0])
            {
                left--;
            }
            while (right < intervals.size() - 1 && intervals[right + 1][0] <= new_interval[1])
            {
                right++;
            }
            intervals[left][0] = intervals[left][0] <= new_interval[0] ? intervals[left][0] : new_interval[0];
            intervals[left][1] = intervals[right][1] >= new_interval[1] ? intervals[right][1] : new_interval[1];
            if (right > left)
            {
                intervals.erase(intervals.begin() + left + 1, intervals.begin() + right + 1);
            }
        }
        return intervals;
    }

};

int main(int argc,char *argv[])
{
    Solution solution;
    //vector<vector<int>> v = {{1, 3}, {5, 6}, {8, 10}, {12, 12}, {15, 18}};
    vector<vector<int>> v = {};
    vector<int> interval = {0, 0};
    print_intervals(v);
    printf("Input: [%d, %d]\n", interval[0], interval[1]);
    vector<vector<int>> ret = solution.insert(v, interval);
    print_intervals(ret);

    fflush(stdout);
    return 0;
}
