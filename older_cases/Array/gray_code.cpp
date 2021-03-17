#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {           
        vector<int> v;
        vector<int> stored;
        if(n == 0) {
            v.push_back(0);
            return v;
        }
        v.push_back(0);
        v.push_back(1);
        int xor_num = 1;
        while((--n) > 0) {
            vector<int>::iterator it = v.end();
            xor_num = xor_num << 1;
            while(it != v.begin()) {
                it--;
                stored.push_back(*it ^ xor_num);
            }
            vector<int>::iterator s_it = stored.begin();
            while(s_it != stored.end()) {
                v.push_back(*s_it);
                s_it++;
            }
            stored.clear();
        }
        return v;
    }
};

int print_binary_code(int a, int n) {
    int i = n - 1;
    while(i >= 0) {
        cout << ((a >> i) & 1);
        i--;
    }
    cout << endl;
    return 0;
}

int main(int argc, char* argv[]) {
    int n = 4;
    Solution s;
    vector<int> v = s.grayCode(n);
    cout << "Gray codes:" << endl;
    vector<int>::iterator it = v.begin();
    while(it != v.end()) {
        print_binary_code(*it, n);
        it++;
    }
    return 0;
}
