#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool check_dot_side(string ss) {
        for(int i = 0; i < ss.size(); i++) {
            if(ss[i] < '0' || ss[i] > '9') {
                return false;
            }
        }
        return true;
    }
    size_t split_string(string &left_string, string &right_string, string &ss, char split_char) {
        size_t len = ss.size();
        size_t split_index = ss.find(split_char);
        if(split_index == string::npos) {
            left_string = ss;
            right_string = "0";
        }
        else {
            left_string = ss.substr(0, split_index);
            right_string = ss.substr(split_index + 1, len - split_index - 1);
        }
        return split_index;
    }
    bool check_e_side(string ss, bool can_dot_exist) {
        if(ss.size() == 0) {
            return false;
        }
        string dot_left_side;
        string dot_right_side;
        if(split_string(dot_left_side, dot_right_side, ss, '.') != string::npos && !can_dot_exist) {
            return false;
        }
        if(dot_left_side.size() == 0 && dot_right_side.size() == 0) {
            return false;
        }
        else {
            dot_left_side.insert(dot_left_side.begin(), '1');
            dot_right_side.insert(dot_right_side.begin(), '0');
        }
        return (check_dot_side(dot_left_side) && check_dot_side(dot_right_side));
    }
    bool isNumber(const char *s) {
        string ss(s);
        // Eliminate spaces in the head and tail of ss
        bool signed_flag = false;
        while(ss.size() != 0 && (ss[0] == ' ' || ss[0] == '+' || ss[0] == '-') && !signed_flag){
            if(ss[0] == '-' || ss[0] == '+') {
                signed_flag = true;
            }
            ss.erase(ss.begin());
        }
        while(ss.size() != 0 && ss[ss.size() - 1] == ' '){
            ss.erase(ss.end() - 1);
        }
        string e_left_side;
        string e_right_side;
        split_string(e_left_side, e_right_side, ss, 'e');
        if(e_right_side[0] == '+' || e_right_side[0] == '-') {
            e_right_side.erase(e_right_side.begin());
        }
        return (check_e_side(e_left_side, true) && check_e_side(e_right_side, false));
    }
};

int main(int argc, char* argv[]) {
    string ss("123e45");
    if(argc == 2) {
        string s_tmp(argv[1]);
        ss = s_tmp;
    }
    cout << ss << endl;
    Solution s;
    bool ret = s.isNumber(ss.c_str());
    if(ret) {
        cout << "This is a number!" << endl;
    }
    else {
        cout << "This is not a number!" << endl;
    }
    return 0;
}
