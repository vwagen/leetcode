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
        int flag = 0;
        for(i = 0, j = 0; i < n; i++, j++) {
            A[j] = A[i];
            while(i < n - 1 && A[i] == A[i + 1] && flag) {
                nums--;
                i++;
            }
            if(i < n - 1 && A[i] == A[i + 1]) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        }
        return nums;
    }
};

int main(int argc, char* argv[]) {
    //int A[5] = {1, 1, 2, 2, 3};
    int A[6] = {1, 1, 1, 2, 2, 3};
    int n = 6;
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
