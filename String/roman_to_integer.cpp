#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        size_t len = s.size();
        int ret = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == 'M') {
                ret += 1000;
            }
            else if(s[i] == 'C') {
                if(i < len - 1 && s[i + 1] == 'M') {
                    ret += 900;
                    i++;
                }
                else if(i < len - 1 && s[i + 1] == 'D') {
                    ret += 400;
                    i++;
                }
                else {
                    ret += 100;
                }
            }
            else if(s[i] == 'D') {
                ret += 500;
            }
            else if(s[i] == 'X') {
                if(i < len - 1 && s[i + 1] == 'C') {
                    ret += 90;
                    i++;
                }
                else if(i < len - 1 && s[i + 1] == 'L') {
                    ret += 40;
                    i++;
                }
                else {
                    ret += 10;
                }
            }
            else if(s[i] == 'L') {
                ret += 50;
            }
            else if(s[i] == 'I') {
                if(i < len - 1 && s[i + 1] == 'X') {
                    ret += 9;
                    i++;
                }
                else if(i < len - 1 && s[i + 1] == 'V') {
                    ret += 4;
                    i++;
                }
                else {
                    ret += 1;
                }
            }
            else if(s[i] == 'V') {
                ret += 5;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    string ss("MDCCCLXXXVIII");
    if(argc == 2) {
        ss = argv[1];
    }
    Solution s;
    cout << ss << " alter to integer is: " << s.romanToInt(ss) << endl;
    //bool ret = s.();
    //if(ret) {
    //    cout << "This is a palindrom!" << endl;
    //}
    //else {
    //    cout << "This is not a palindrom!" << endl;
    //}
    return 0;
}
