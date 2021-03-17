#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i;
        int j;
        int nums = n;
        for(i = 0, j = 0; i < n; i++, j++) {
            A[j] = A[i];
            while(i < n - 1 && A[i] == A[i + 1]) {
                nums--;
                i++;
            }
        }
        return nums;
    }
};

int main(int argc, char* argv[]) {
    //int A[5] = {1, 1, 2, 2, 3};
    int A[0] = {};
    int n = 0;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Solution s;
    n = s.removeDuplicates(A, n);
    cout << "Result is :" << n << endl << "Now A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
