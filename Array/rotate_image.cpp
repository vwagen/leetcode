#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    int swap(int &a, int &b) {
        a ^= b;
        b ^= a;
        a ^= b;
        return 0;
    }
    void rotate(vector<vector<int> > &matrix) {
        int n = (int) matrix.size();
        int line;
        int row;
        for(line = 0, row = 0; row < n; row++) {
            int i = line;
            int j = row;
            while(i < j) {
                swap(matrix[i][j], matrix[j][i]);
                i++;
                j--;
            }
        }
        for(line = 1, row = n - 1; line < n; line++) {
            int i = line;
            int j = row;
            while(i < j) {
                swap(matrix[i][j], matrix[j][i]);
                i++;
                j--;
            }
        }
        for(line = 0; line < n; line++) {
            int i = 0;
            int j = n - 1;
            while(i < j) {
                swap(matrix[line][i], matrix[line][j]);
                i++;
                j--;
            }
        }
        return;
    }
};

int main(int argc, char* argv[]) {
    vector<int> v;
    vector<vector<int> > b;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    b.push_back(v);
    v.clear();
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    b.push_back(v);
    v.clear();
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    b.push_back(v);
    v.clear();
    Solution s;
    s.rotate(b);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
