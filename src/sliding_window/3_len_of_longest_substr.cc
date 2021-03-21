#include "map_cases.hh"
using namespace std;

class Solution
{
public:
    static void set_bit(unsigned long long* bit_map, char c)
    {
        bit_map[c / 64] |= ((unsigned long long)1 << c % 64);
    }

    static void unset_bit(unsigned long long* bit_map, char c)
    {
        bit_map[c / 64] &= ~((unsigned long long)1 << c % 64);
    }

    static bool has_bit(unsigned long long* bit_map, char c)
    {
        return bit_map[c / 64] & ((unsigned long long)1 << c % 64);
    }

    int lengthOfLongestSubstring(string s)
    {
        unsigned long long bit_map[4] = {0};
        unsigned int s_len = s.size();
        int cur_substr_len = 0;
        int ret = 0;
        unsigned int begin = 0, end = 0;
        while (end < s_len)
        {
            while (end < s_len && !has_bit(bit_map, s[end]))
            {
                set_bit(bit_map, s[end]);
                cur_substr_len++;
                end++;
            }
            ret = ret < cur_substr_len ? cur_substr_len : ret;
            while (end < s_len && has_bit(bit_map, s[end]))
            {
                unset_bit(bit_map, s[begin]);
                cur_substr_len--;
                begin++;
            }
        }
        return ret;
    }
};

void run_len_of_longest_substr_3()
{
    Solution solution;
    const char* s = "abcdabc";
    printf("%d\n", solution.lengthOfLongestSubstring(s));
}