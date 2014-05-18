#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {          
        if(n < 3) {
            return n;
        }
        int* N = new int[n];
        N[0] = 1;
        N[1] = 2;
        for(int i = 2; i < n; i++) {
            N[i] = N[i - 1] + N[i - 2];
        }
        int ret = N[n - 1];
        delete N;
        return ret;
    }
};

int main(int argc, char* argv[]) {
    int n = 44;
    Solution s;
    cout << "climbing ways: " << s.climbStairs(n) << endl;
    return 0;
}
