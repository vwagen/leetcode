#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        const char* ac = a.c_str();
        const char* bc = b.c_str();
        int len = (len_a > len_b ? len_a : len_b) + 1;
        char* tmp = new char[len + 1];
        tmp [len] = '\0';
        int i = len_a - 1;
        int j = len_b - 1;
        int k = len - 1;
        char carry = '0';
        char* ret;
        while(i != -1 && j != -1) {
            char a_char = ac[i];
            char b_char = bc[j];
            if((a_char == '0' && b_char == '1') || (a_char == '1' && b_char == '0')) {
                if(carry == '0') {
                    tmp[k] = '1';
                }
                else {
                    tmp[k] = '0';
                }
            }
            else {
                if(carry == '0') {
                    tmp[k] = '0';
                }
                else {
                    tmp[k] = '1';
                }
                if(a_char == '1' && b_char == '1') {
                    carry = '1';
                }
                else {
                    carry = '0';
                }
            }
            k--;
            i--;
            j--;
        }
        if(i == -1 && j != -1) {
            while(j != -1) {
                char b_char = bc[j];
                if((b_char == '0' && carry == '1') || (b_char == '1' && carry == '0')) {
                    tmp[k] = '1';
                    carry = '0';
                }
                else if(b_char == '0' && carry == '0') {
                    tmp[k] = '0';
                }
                else {
                    tmp[k] = '0';
                    carry = '1';
                }
                k--;
                j--;
            }
        }
        else if(i != -1 && j == -1) {
            while(i != -1) {
                char a_char = ac[i];
                if((a_char == '0' && carry == '1') || (a_char == '1' && carry == '0')) {
                    tmp[k] = '1';
                    carry = '0';
                }
                else if(a_char == '0' && carry == '0') {
                    tmp[k] = '0';
                }
                else {
                    tmp[k] = '0';
                    carry = '1';
                }
                k--;
                i--;
            }
        }
        if(carry == '1') {
            tmp[k] = '1';
            ret = tmp;
        }
        else {
            ret = tmp + 1;
        }
        return string(ret);
    }
};

int main(int argc, char* argv[]) {
    string s1("1");
    cout << s1 << endl;
    string s2("1");
    cout << s2 << endl;
    Solution s;
    cout << "Sum: " << s.addBinary(s1, s2) << endl;
    //bool ret = s.();
    //if(ret) {
    //    cout << "This is a palindrom!" << endl;
    //}
    //else {
    //    cout << "This is not a palindrom!" << endl;
    //}
    return 0;
}
