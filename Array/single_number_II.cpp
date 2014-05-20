#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int bits[32] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 32; j++) {
                bits[j] += ((A[i] >> (31 - j)) & 1);
            }
        }
        int ret = 0;
        for(int j = 0; j < 32; j++) {
            ret = ret | ((bits[j] % 3) << (31 - j));
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    int A[10] = {-1, -1, -1, 2, 2, 2, 3, 3, 3, -4};
    int n = 10;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Solution s;
    n = s.singleNumber(A, n);
    cout << "Result is : " << n << endl;
    return 0;
}
