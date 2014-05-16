#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public: 
    int swap(vector<int>::iterator it1, vector<int>::iterator it2) {
        *it1 ^= *it2;
        *it2 ^= *it1;
        *it1 ^= *it2;
        return 0;
    }
    void nextPermutation(vector<int> &num) {       
        if(num.size() == 0) {
            return;
        }
        vector<int>::iterator it_high = num.end() - 1;
        vector<int>::iterator it_sec = num.end() - 1;
        vector<int>::iterator it_low = num.end() - 1;
        vector<int>::iterator it_bigger_than_high;
        while(*it_high >= *it_sec && it_high != num.begin()) {
            it_high--;
            it_sec = it_high + 1;
        }
        if(*it_high < *it_sec) {
            it_bigger_than_high = it_low;
            while(*it_high >= *it_bigger_than_high) {
                it_bigger_than_high--;
            }
            swap(it_high, it_bigger_than_high);
            it_high = it_sec;
        }
        while(it_high < it_low) {
            swap(it_high, it_low);
            it_high++;
            it_low--;
        }
        return;
    }
};

int main(int argc, char* argv[]) {
    vector<int> num;
    int max = 9;
    num.push_back(1);
    for(int i = max; i > 0; i--) {
        num.push_back(i);
        num.push_back(i);
    }
    copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    Solution s;
    bool flag = false;
    //while(!flag) {
    //    flag = s.nextPermutation(num);
    //    copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
    //    cout << endl;
    //}
    s.nextPermutation(num);
    copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
