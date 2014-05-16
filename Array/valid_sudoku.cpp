#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public: 
    int swap(int A[], int a, int b) {
        A[a] ^= A[b];
        A[b] ^= A[a];
        A[a] ^= A[b];
        return 0;
    }
    bool check_valid(int A[], int n) {
        for(int i = 0; i < n; ) {
            if(A[i] < 0 || A[i] == i) {
                i++;
                continue;
            }
            if(A[i] != A[A[i]]) {
                swap(A, i, A[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        int A[9];
        int line;
        int row;
        bool flag = true;
        for(line = 0; line < 9 && flag == true; line++) {
            for(row = 0; row < 9; row++) {
                A[row] = (int)(board[line][row] - '1');
            }
            flag = check_valid(A, 9);
        }
        for(row = 0; row < 9 && flag == true; row++) {
            for(line = 0; line < 9; line++) {
                A[line] = (int)(board[line][row] - '1');
            }
            flag = check_valid(A, 9);
        }
        for(line = 0; line < 9 && flag == true; line += 3) {
            for(row = 0; row < 9 && flag == true; row += 3) {
                for(int k = 0; k < 9; k++) {
                    A[k] = (int)(board[line + (k / 3)][row + (k % 3)] - '1');
                }
                flag = check_valid(A, 9);
            }
        }
        return flag;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
