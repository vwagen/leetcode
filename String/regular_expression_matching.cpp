#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;



// Remember, delete those "cout" lines & "copy" lines in class Solution before copy this code to leetcode.
class Solution {
public:
    int strStr(char *haystack, char *needle) {
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
            while(needle[k] == '.' || haystack[j] == needle[k]) {
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
        cout << endl << "--  ^^  **  &&    A new is Match --  ^^  **  &&";
        while(s[i] != '\0' && p[j] != '\0') {
            if(p[j + 1] != '*') {
                if(p[j] == '.' || s[i] == p[j]) {
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
                //cout << endl << "p is: " << p << endl;
                //cout << "p[" << m << "]: " << p[m] << "     p[" << m + 1 << "]: " << p[m + 1] << endl;
                while(p[m] != '\0' && p[m + 1] == '*') {
                    m += 2;
                }
                int n = m;
                //cout << "m: " << m << " n: " << n << endl;
                while(p[n] != '\0' && p[n + 1] != '*') {
                    n++;
                }
                //cout << "m: " << m << " n: " << n << endl;
                char* p_tmp = new char[n - m + 1];
                for(int l = 0; l < n - m; l++) {
                    p_tmp[l] = p[m + l];
                }
                p_tmp[n - m] = '\0';
                //cout << "p_tmp now is: " << p_tmp << endl;
                int s_match_index_max;
                int p_match_index_max = m;
                int k = i;
                bool flag = false;
                int match_index;



                cout << endl;
                cout << "s is: " << s << endl;
                cout << "p is: " << p << endl;
                cout << "p_tmp now is: " << p_tmp << endl;
                cout << "--------------------------------------" << endl;
                while(flag == false) {
                    match_index = strStr((char*)(&s[k]), p_tmp);
                    cout << "search " << p_tmp << " in " << &s[k] << "      index is(match_index): " << match_index << endl;
                    if(match_index == -1) {
                        cout << "Not found, and return" << endl;
                        cout << "--  ^^  **  &&   $ $ $ $ $ $ $ $ $ $   --  ^^  **  &&" << endl << endl;
                        return false;
                    }
                    else {
                        s_match_index_max = k + match_index;
                        match_star_i = i;
                        match_star_j = j;
                        //--------------------------------------------------
                        cout << "test ";
                        copy(&p[match_star_j], &p[p_match_index_max], ostream_iterator<char>(cout, ""));
                        cout << " with ";
                        copy(&s[match_star_i], &s[s_match_index_max], ostream_iterator<char>(cout, ""));
                        cout << "           Result: ";
                        //--------------------------------------------------
                        while(match_star_i < s_match_index_max && match_star_j < p_match_index_max) {
                            if(p[match_star_j] == '.' || s[match_star_i] == p[match_star_j]) {
                                match_star_i++;
                            }
                            else {
                                match_star_j += 2;
                            }
                        }
                        if(match_star_i < s_match_index_max) {
                            cout << "Not match, and return" << endl;
                            cout << "--  ^^  **  &&   $ $ $ $ $ $ $ $ $ $   --  ^^  **  &&" << endl << endl;
                            return false;
                        }
                        cout << "Match" << endl;
                        cout << "Next isMatch parameters are s: " <<  &s[s_match_index_max] << "          p: " << &p[p_match_index_max] << endl;
                        flag = isMatch((const char*)&s[s_match_index_max], (const char*)&p[p_match_index_max]);
                    }
                    k = s_match_index_max + 1;
                }
                return flag;
            }
        }
        while(p[j] != '\0' && p[j + 1] == '*') {
            j += 2;
        }
        if(s[i] == '\0' && p[j] == '\0') {
            cout << endl << "##############################" << endl;
            cout << "p:   " << p << " matches s:    " << s << endl;
            cout << "##############################" << endl;
            cout << "--  ^^  **  &&   ###################  --  ^^  **  &&" << endl << endl;
            return true;
        }
        else {
            cout << endl << "$ $ $ $ $ $ $ $ $ $ $ $ $ $ $ " << endl;
            cout << "p:   " << p << "      do not match s:      " << s << endl;
            cout << "$ $ $ $ $ $ $ $ $ $ $ $ $ $ $ " << endl << endl;
            cout << "--  ^^  **  &&   $ $ $ $ $ $ $ $ $ $   --  ^^  **  &&" << endl << endl;
            return false;
        }
    }
};

int main(int argc, char* argv[]) {
    char *s = "abcdefghijj";
    char *p = "a.c.*jj";
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
