#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<size_t> lengths;
            size_t s_length = s.length();
            if(s_length == 0) {
                return 0;
            }
            int a[128] = {0};
            size_t end;
            size_t begin;
            char c_tmp;
            for(end = 0, begin = 0; end < s_length; end++) {
                c_tmp = s[end];
                if(a[c_tmp] == 0) {
                    a[c_tmp] = 1;
                    continue;
                }
                //cout << "end :" << end << " begin: " << begin << endl;
                lengths.push_back((int)(end - begin));
                while(s[begin++] != c_tmp) {
                    a[s[begin - 1]] = 0;
                }
            }
            //cout << "end :" << end << " begin: " << begin << endl;
            lengths.push_back((int)(end - begin));
            int max = lengths[0];
            int i;
            int l_size = (int)lengths.size();
            for(i = 0; i < l_size; i++) {
                //cout << "lengths[" << i << "] = " << lengths[i] << endl;
                max = max >= lengths[i] ? max : lengths[i];
            }
            return max;
        }
};
int main(int argc, char* argv[]) {
    int num = 12;
    string s[num];
    s[0] = "";
    s[1] = "a";
    s[2] = "aa";
    s[3] = "aaaa";
    s[4] = "aba";
    s[5] = "abb";
    s[6] = "abbb";
    s[7] = "abbbb";
    s[8] = "abcbbb";
    s[9] = "abcdcb";
    s[10] = "abcdefg";
    s[11] = "abcd!@#$*502efg";
    int i;
    Solution sol;
    for(i = 0; i < num; i++) {
        cout << s[i] << "   :   " << sol.lengthOfLongestSubstring(s[i]) << endl << endl << endl;
    }
    return 0;
}
