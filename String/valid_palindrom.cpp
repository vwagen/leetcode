#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if(len == 0) {
            return true;
        }
        const char* c = s.c_str();
        char* str = new char[len + 1];
        int i;
        int j;
        for(i = 0, j = 0; i < len; i++) {
            if((c[i] >= '0' && c[i] <= '9') || (c[i] >= 'a' && c[i] <= 'z')) {
                str[j] = c[i];
                j++;
            }
            else if((c[i] >= 'A' && c[i] <= 'Z')) {
                str[j] = c[i] + ('a' - 'A');
                j++;
            }
        }
        str[j] = '\0';
        //For testing
        //----------------------
        cout << str << endl;
        //----------------------
        int m = 0;
        int n = j - 1;
        for(; m < n; m++, n--) {
            if(str[m] != str[n]) {
                break;
            }
        }
        free(str);
        if(m < n) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main(int argc, char* argv[]) {
    string ss;
    if(argc == 2) {
        ss = argv[1];
    }
    else {
        ss = "A man, a plan, a canal: Panama";
    }
    cout << ss << endl;
    Solution s;
    bool ret = s.isPalindrome(ss);
    if(ret) {
        cout << "This is a palindrom!" << endl;
    }
    else {
        cout << "This is not a palindrom!" << endl;
    }
    return 0;
}
