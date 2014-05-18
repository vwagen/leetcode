#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int* gas_gain = new int[n];
        for(int i = 0; i < n; i++) {
            gas_gain[i] = gas[i] - cost[i];
        }
        int j = 0;
        int k = 0;
        int gain = 0;
        do {
            if(gain >= 0) {
                gain += gas_gain[k];
                k = (k + 1) % n;
            }
            else {
                j = (j - 1 + n) % n;
                gain += gas_gain[j];
            }
        } while(j != k);
        delete gas_gain;
        if(gain < 0) {
            return -1;
        }
        else {
            return j;
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> gas;
    vector<int> cost;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(3);
    cost.push_back(2);
    cost.push_back(1);
    cost.push_back(5);
    cost.push_back(1);
    Solution s;
    cout << "Result: " << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
