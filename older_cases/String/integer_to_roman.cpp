#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int quotient;
        int remainder;
        int m = 1000;
        char* c = "IVXLCDM**";
        int index = 6;
        int i = 0;
        int j = 0;
        int k = 0;
        int l = 0;
        string ret("");
        do {
            quotient = num / m;
            remainder = num % m;
            // i, j, k & l specify that how many characters there should be. i.e. c[index](num:i) c[index + 1](num:j) c[index](num:k) c[index + 2](num:l).
            // e.g. while i = 0, j = 1, k = 3, l = 0, index is 0, that means 0 "I", 1 "V", 3 "I"s, and 0 "X". It is VIII.
            if(quotient == 4) {
                i = 1;
            }
            else {
                i = 0;
            }
            if(quotient >= 4 && quotient < 9){
                j = 1;
            }
            else {
                j = 0;
            }
            if(quotient <= 4 || quotient == 9) {
                k = quotient % 4;
            }
            else {
                k = (quotient - 5) % 4;
            }
            if(quotient == 9) {
                l = 1;
            }
            else {
                l = 0;
            }
            for(int q = 0; q < i; q++) {
                ret.push_back(c[index]);
            }
            for(int q = 0; q < j; q++) {
                ret.push_back(c[index + 1]);
            }
            for(int q = 0; q < k; q++) {
                ret.push_back(c[index]);
            }
            for(int q = 0; q < l; q++) {
                ret.push_back(c[index + 2]);
            }
            num = remainder;
            index -= 2;
            m /= 10;
        } while(m > 0);
        return ret;
    }
};

int main(int argc, char* argv[]) {
    int ss = 3999;
    if(argc == 2) {
        ss = atoi(argv[1]);
    }
    Solution s;
    cout << ss << " alter to roman is: " << s.intToRoman(ss) << endl;
    //bool ret = s.();
    //if(ret) {
    //    cout << "This is a palindrom!" << endl;
    //}
    //else {
    //    cout << "This is not a palindrom!" << endl;
    //}
    return 0;
}
