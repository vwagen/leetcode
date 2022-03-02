#include "utils.hh"
#include <algorithm>
using namespace std;

/*
 * 思路1：排序后归并。
 * 思路2：用数组记录区间起始和区间结束，起始加 1，结束减 -1。最后从头遍历数组，并用一个 cnt 加数组中遍历到的值。
 * 当数组变成非零之后再变回零，表示发现一个区间。不过要另外处理 [1,1] 这种起始和结束相同的区间，因为这个会让数组
 * 相应位置为 0，在遍历中会检查不出来。
 * */
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

int main(int argc,char *argv[])
{
    Solution solution;
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {12, 12}, {15, 18}};
    print_intervals(v);
    vector<vector<int>> ret = solution.merge_not_sort(v);
    print_intervals(ret);

    fflush(stdout);
    return 0;
}
