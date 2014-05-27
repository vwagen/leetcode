#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;




















// Remember, delete those "cout" lines & "copy" lines in class Solution before copy this code to leetcode.
class Solution {
public:
    int find_needle_in_haystack(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL) {
            return -1;
        }
        if(haystack[0] == '\0' && needle[0] == '\0') {
            return 0;
        }
        else if(haystack[0] == '\0' && needle[0] != '\0') {
            return -1;
        }
        else if(haystack[0] != '\0' && needle[0] == '\0') {
            return 0;
        }
        int i = 0;
        int j;
        int k;
        while(haystack[i] != '\0') {
            k = 0;
            j = i;
            while(needle[k] == '?' || haystack[j] == needle[k]) {
                if(haystack[j + 1] == '\0' && needle[k + 1] != '\0') {
                    return -1;
                }
                if(needle[k + 1] == '\0') {
                    return i;
                }
                j++;
                k++;
            }
            i++;
        }
        return -1;
    }
    bool isMatch(const char *s, const char *p) {
        int i = 0;
        int j = 0;
        while(s[i] != '\0' && p[j] != '\0') {
            if(p[j] != '*') {
                if(p[j] == '?' || s[i] == p[j]) {
                    i++;
                    j++;
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                int match_star_i;
                int match_star_j;
                int m = j;
                while(p[m] != '\0' && p[m] == '*') {
                    m++;
                }
                int n = m;
                while(p[n] != '\0' && p[n] != '*') {
                    n++;
                }
                char* p_tmp = new char[n - m + 1];
                for(int l = 0; l < n - m; l++) {
                    p_tmp[l] = p[m + l];
                }
                p_tmp[n - m] = '\0';
                
                int s_match_index_max;
                int p_match_index_max = m;
                int match_index;
                int k = i;
                bool flag = false;
                bool is_next_a_star;
                if(p[n] == '*') {
                    is_next_a_star = true;
                }
                else {
                    is_next_a_star = false;
                }



                do{
                    match_index = find_needle_in_haystack((char*)(&s[k]), p_tmp);
                    if(match_index == -1) {
                        free(p_tmp);
                        return false;
                    }
                    else {
                        s_match_index_max = k + match_index;
                        flag = isMatch((const char*)&s[s_match_index_max], (const char*)&p[p_match_index_max]);
                    }
                    k = s_match_index_max + 1;
                }while(flag == false && is_next_a_star == false);
                free(p_tmp);
                return flag;
            }
        }
        while(p[j] != '\0' && p[j] == '*') {
            j++;
        }
        if(s[i] == '\0' && p[j] == '\0') {
            return true;
        }
        else {
            return false;
        }
    }
};

int main(int argc, char* argv[]) {
    char *s = "abcdefghijj";
    char *p = "a?c?*jj";
    if(argc == 2) {
        s = argv[1];
    }
    if(argc == 3) {
        s = argv[1];
        p = argv[2];
    }
    Solution sol;
    cout << "s: " << s << endl;
    cout << "p: " << p << endl;
    cout << "Regular match?" << endl;
    if(sol.isMatch((const char*)s, (const char*)p)) {
        cout << "Yes!" << endl;
    }
    else {
        cout << "No!" << endl;
    }
    return 0;
}
