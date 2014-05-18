#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    typedef struct {
        int i;
        int j;
    } indices;
    void findIndex(vector<vector<int> > &matrix, int &i, int &j) {
        int line_max = matrix.size();
        int row_max = matrix[0].size();
        for(; i < line_max; i++) {
            for(; j < row_max; j++){
                if(matrix[i][j] == 0) {
                    return;
                }
            }
            j = 0;
        }
        return;
    }
    void zero_indices(vector<indices> &storing, vector<vector<int> > &matrix) {
        int line_max = matrix.size();
        int row_max = matrix[0].size();
        int i = 0;
        int j = -1;
        while(1) {
            j++;
            findIndex(matrix, i, j);
            if(i == line_max || j == row_max) {
                return;
            }
            indices ind = {i, j};
            storing.push_back(ind);
        }
    }
    void setZeroes(vector<vector<int> > &matrix) {
        int i;
        int j;
        int line_max = matrix.size();
        int row_max = matrix[0].size();
        vector<indices> storing;
        zero_indices(storing, matrix);
        vector<indices>::iterator it = storing.begin();
        while(it != storing.end()) {
            i = (*it).i;
            j = (*it).j;
            for(int row = 0; row < row_max; row++) {
                matrix[i][row] = 0;
            }
            for(int line = 0; line < line_max; line++) {
                matrix[line][j] = 0;
            }
            it++;
        }
        return;
    }
};

int print_matrix(vector<vector<int> > &matrix) {
    int line_max = matrix.size();
    int row_max = matrix[0].size();
    int i = 0;
    int j = 0;
    for(; i < line_max; i++) {
        for(j = 0; j < row_max; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    vector<vector<int> > v;
    vector<int> vv;
    //[[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
    vv.push_back(0);vv.push_back(0);vv.push_back(0);vv.push_back(1);
    v.push_back(vv);
    vv.clear();
    vv.push_back(4);vv.push_back(3);vv.push_back(1);vv.push_back(4);
    v.push_back(vv);
    vv.clear();
    vv.push_back(0);vv.push_back(1);vv.push_back(1);vv.push_back(4);
    v.push_back(vv);
    vv.clear();
    vv.push_back(1);vv.push_back(2);vv.push_back(1);vv.push_back(3);
    v.push_back(vv);
    vv.clear();
    vv.push_back(0);vv.push_back(0);vv.push_back(1);vv.push_back(1);
    v.push_back(vv);
    vv.clear();
    print_matrix(v);
    Solution s;
    s.setZeroes(v);
    cout << "---------------Result-----------------" << endl;
    print_matrix(v);
    return 0;
}
