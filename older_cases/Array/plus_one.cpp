#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.size() == 0) {
            digits.push_back(1);
            return digits;
        }
        vector<int>::iterator it = digits.end();
        int signed_flag = 1;
        while(it != digits.begin() && signed_flag) {
            it--;
            int tmp = signed_flag + *it;
            *it = tmp % 10;
            signed_flag = tmp / 10;
        }
        if(signed_flag == 1) {
            digits.insert(it, 1);
        }
        return digits;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A;
    A.push_back(9);
    A.push_back(9);
    A.push_back(9);
    cout << "digits is: " << endl;
    copy(A.begin(), A.end(), ostream_iterator<int>(cout, ""));
    cout << endl;
    Solution s;
    s.plusOne(A);
    cout << "After plus one digits is: " << endl;
    copy(A.begin(), A.end(), ostream_iterator<int>(cout, ""));
    cout << endl;
    return 0;
}
