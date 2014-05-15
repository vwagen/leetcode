#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
    public: 
        int search(int A[], int n, int target){
            int begin = 0;
            int end = n - 1;
            int mid = 0;
            while(1) {
                mid = (begin + end) / 2;
                if(A[mid] == target) {
                    return mid;
                }
                if(end > begin) {
                    if(A[begin] >= A[end]) {
                        if((target >= A[begin] && target >= A[mid] && target >= A[end]) ||
                           (target <= A[begin] && target <= A[mid] && target <= A[end])) {
                            if(A[begin] > A[mid]) {
                                end = mid - 1;
                            }
                            else{
                                begin = mid + 1;
                            }
                        }
                        else {
                            if(A[begin] > A[mid]) {
                                begin = mid + 1;
                            }
                            else{
                                end = mid - 1;
                            }
                        }
                    }
                    else {
                        if(target >= A[begin] && target <= A[mid] && target <= A[end]) {
                            end = mid - 1;
                        }
                        else {
                            begin = mid + 1;
                        }
                    }
                }
                else {
                    break;
                }
            }
            return -1;
        }
};

int main(int argc, char* argv[]) {
    int A[1] = {4};
    int n = 1;
    int target = 4;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Solution s;
    cout <<  "The index of target \"" << target << "\" is: " << s.search(A, n, target) << endl;
    return 0;
}
