#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
    public: 
        bool search_for_it(int A[], int begin, int end, int target) {
            int mid = 0;
            while(1) {
                mid = (begin + end) / 2;
                if(A[mid] == target) {
                    return true;
                }
                if(end > begin) {
                    if(A[begin] == A[mid] && A[mid] == A[end]) {
                        if(search_for_it(A, begin, mid - 1, target) == false) {
                            return search_for_it(A, mid + 1, end, target);
                        }
                        else{
                            return true;
                        }
                    }
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
            return false;
        }
        bool search(int A[], int n, int target){
            return search_for_it(A, 0, n - 1, target);
        }
};

int main(int argc, char* argv[]) {
    int A[5] = {1,3,1,1,1};
    int n = 5;
    int target = 3;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Solution s;
    cout <<  "The index of target \"" << target << "\" is: " << s.search(A, n, target) << endl;
    return 0;
}
