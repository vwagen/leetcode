#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while(s[len] != '\0') {
            len++;
        }
        int last_word_length = 0;
        int i = len - 1;
        while(i >= 0 && (s[i] == ' ' || s[i] == '\0')) {
            i--;
        }
        for(; i >= 0 && s[i] != ' '; i--) {
            last_word_length++;
        }
        return last_word_length;
    }
};

int main(int argc, char* argv[]) {
    string ss("This is a string!");
    if(argc == 2) {
        ss = argv[1];
    }
    cout << ss << endl;
    Solution s;
    cout << ss << endl << "The length of last word is:" << endl;
    cout << s.lengthOfLastWord(ss.c_str()) << endl;
    //bool ret = s.();
    //if(ret) {
    //    cout << "This is a palindrom!" << endl;
    //}
    //else {
    //    cout << "This is not a palindrom!" << endl;
    //}
    return 0;
}
