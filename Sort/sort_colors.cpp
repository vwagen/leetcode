#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0;
        int right = n - 1;
        while(left < right) {
            while((A[left] != 1 || A[right] != 1) && (left < right)) {  // While left < right and both A[left] and A[right] are not 1s.
                if(A[left] > A[right]) {                                // Switch A[left] and A[right] if A[left] is less than A[right].
                    A[left] ^= A[right];
                    A[right] ^= A[left];
                    A[left] ^= A[right];
                }
                if(A[left] == 0) {                                      // If A[left] equals 0, that means left side are 0s.
                    left++;
                }
                if(A[right] == 2) {                                     // If A[right] equals 2, that means right side are 2s.
                    right--;
                }
            }
            int index = left;                                           // A index used for Searching elements those are not 1s.
            while((A[left] == 1 && A[right] == 1) && (left < right) && index < right) {
                while(index < right && A[index] == 1) {                 // Search the element which is not 1.
                    index++;
                }
                if(A[index] == 0) {
                    A[left] ^= A[index];
                    A[index] ^= A[left];
                    A[left] ^= A[index];
                    left++;
                }
                else if(A[index] == 2) {
                    A[index] ^= A[right];
                    A[right] ^= A[index];
                    A[index] ^= A[right];
                    right--;
                }
            }
            if(index == right) {                                        // If index equals right, that means all is ordered.
                break;
            }
        }
        return;
    }
};

int main() {
    int A[] = {2,1,2,1,2,1,0,1,1,0,0};
    int B[] = {};
    int C[] = {1};
    Solution s;
    int lenA = sizeof(A) / sizeof(int);
    int lenB = sizeof(B) / sizeof(int);
    int lenC = sizeof(C) / sizeof(int);
    s.sortColors(A, lenA);
    s.sortColors(B, lenB);
    s.sortColors(C, lenC);
    cout << "A[]: ";
    copy(A, A + lenA, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "B[]: ";
    copy(B, B + lenB, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "C[]: ";
    copy(C, C + lenC, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
