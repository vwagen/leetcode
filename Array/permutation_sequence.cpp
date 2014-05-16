#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public: 
    int swap(char* A, int a, int b) {
        A[a] ^= A[b];
        A[b] ^= A[a];
        A[a] ^= A[b];
        return 0;
    }
    bool nextPermutation(char* A, int n) {       
        if(n == 0) {
            return true;
        }
        int it_high = n - 1;
        int it_sec = n - 1;
        int it_low = n - 1;
        int it_bigger_than_high;
        while(A[it_high] >= A[it_sec] && it_high != 0) {
            it_high--;
            it_sec = it_high + 1;
        }
        if(A[it_high] < A[it_sec]) {
            it_bigger_than_high = it_low;
            while(A[it_high] >= A[it_bigger_than_high]) {
                it_bigger_than_high--;
            }
            swap(A, it_high, it_bigger_than_high);
            it_high = it_sec;
        }
        while(it_high < it_low) {
            swap(A, it_high, it_low);
            it_high++;
            it_low--;
        }
        return false;
    }
    string getPermutation(int n, int k){
        char* A = new char[n];
        for(int i = 0; i < n; i++) {
            A[i] = i + 1 + '0';
        }
        while(k-- > 1) {
            nextPermutation(A, n);
        }
        string ret = "";
        for(int j = 0; j < n; j++){
            ret += A[j];
        }
        delete(A);
        return ret;
    }
};

int main(int argc, char* argv[]) {
    int n = 7;
    int k = 4402;
    Solution s;
    cout << "n: " << n << " k: " << k << endl;
    cout << "Result is: " << s.getPermutation(n, k) << endl;
    return 0;
}
