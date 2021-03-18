#include "sorting.hh"
#include <algorithm>
using namespace std;

void print_intervals(const vector<vector<int>>& v)
{
    printf("[");
    for (int i = 0; i < v.size(); i++)
    {
        printf("[%d, %d]%s", v[i][0], v[i][1], i < v.size() - 1 ? ", " : "");
    }
    printf("]\n");
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {return a[0] < b[0];});
        vector<vector<int>> ret;
        if (!intervals.empty())
        {
            ret.push_back(intervals[0]);
        }
        for (int i = 0, j = 0; j < intervals.size(); j++)
        {
            if (ret[i][1] >= intervals[j][0])
            {
                ret[i][0] = ret[i][0] <= intervals[j][0] ? ret[i][0] : intervals[j][0];
                ret[i][1] = ret[i][1] >= intervals[j][1] ? ret[i][1] : intervals[j][1];
            }
            else
            {
                ret.push_back(intervals[j]);
                i++;
            }
        }
        return ret;
    }

    vector<vector<int>> merge_not_sort(vector<vector<int>>& intervals)
    {
        int array[10000] = {0};
        int array_2[10000] = {0};
        for (auto& v : intervals)
        {
            array[v[0]]++;
            array[v[1]]--;
            if (v[0] == v[1])
            {
                array_2[v[0]] = 1;
            }
        }
        vector<vector<int>> ret;
        int start = -1;
        for (int cnt = 0, i = 0; i < 10000; i++)
        {
            if (start == -1 && array[i] > 0)
            {
                start = i;
                cnt += array[i];
            }
            else if (start == -1 && array_2[i] > 0)
            {
                ret.push_back({i, i});
            }
            else if (start > -1 && !(cnt = cnt + array[i]))
            {
                ret.push_back({start, i});
                start = -1;
            }
        }
        return ret;
    }

};

void run_merge_intervals_56()
{
    Solution solution;
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {12, 12}, {15, 18}};
    print_intervals(v);
    vector<vector<int>> ret = solution.merge_not_sort(v);
    print_intervals(ret);
}
