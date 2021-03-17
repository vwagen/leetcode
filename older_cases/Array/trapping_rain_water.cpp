#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if(n < 3) {
            return 0;
        }
        int drops = 0;
        int left = 0;
        int right = 0;
        int thread;
        int i;
        bool flag = false;
        while(left < n - 1 && right < n - 1) {
            left = right;
            while(left < n - 1 && A[left] <= A[left + 1]) {
                left++;
            }
            right = left;
            while(right < n - 1 && A[right] >= A[right + 1]) {
                right++;
            }
            while(right < n - 1 && A[right] < A[left]) {
                right++;
            }
            if(right == n - 1 && A[left] > A[right]) {
            flag = true;}
            if(flag == true) {
                int index = left + 1;
                int max = A[index];
                right = index;
                while(index < n) {
                    if(A[index] > max) {
                        max = A[index];
                        right = index;
                    }
                    index++;
                }
            }
            flag = false;
            thread = A[left] > A[right] ? A[right] : A[left];
            cout << "left: " << left << " right: " << right << " thread: " << thread << endl;
            for(i = left + 1; i < right; i++) {
                if(thread - A[i] >= 0) {
                    drops += thread - A[i];
                }
            }
        }
        return drops;
    }
};

int main(int argc, char* argv[]) {
    int n = 9;
    int A[9] = {2,8,5,5,6,1,7,4,5};
    Solution s;
    copy(A, A + n, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "drops: " << s.trap(A, n) << endl;
    return 0;
}
