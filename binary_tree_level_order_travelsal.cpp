#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef struct TreeN{ 
    int val; 
    TreeN *left; 
    TreeN *right; 
    TreeN(int x) : val(x), left(NULL), right(NULL) {} 
} TreeNode; 

class Solution {
    public:    
        vector<vector<int> > levelOrder(TreeNode *root) {
            vector<vector<int> > r;
            if(root == NULL) {
                return r;
            }
            execute(root, 0, &r);
            return r;
        }
    private:
        void execute(TreeNode* parent, unsigned int level, vector<vector<int> > *vec) {
            if(vec -> size() == level) {
                vector<int> level_vector;
                vec -> push_back(level_vector);
            }
            (*vec)[level].push_back(parent -> val);
            if(parent -> left != NULL) {
                execute(parent -> left, level + 1, vec);
            }
            if(parent -> right != NULL) {
                execute(parent -> right, level + 1, vec);
            }
        }
};

int main(int argc, char* argv[]) {
    vector<int> v;
    int i;
    //int s = atoi(argv[1]);
    //for(i = 0; i < s; i++) {
    //    v.push_back(i);
    //    cout << "i = " << i << " v.size():" << v.size() << endl;
    //}
    //vector<int>::iterator it = v.begin();
    //int itt = 0;
    //while(it != v.end()) {
    //    cout << "v.[" << "] = " << *it++ << endl;
    //}
    //while(itt < v.size() + 1) {
    //    cout << "v[" << itt << "] = " << v[itt] << endl;
    //    itt++;
    //}
    TreeNode root(0);
    TreeNode left(1);
    TreeNode right(2);
    root.left = &left;
    root.right = &right;
    TreeNode left1(3);
    TreeNode right1(4);
    left.left = &left1;
    left.right = &right1;
    TreeNode left2(5);
    TreeNode right2(6);
    right.left = &left2;
    right.right = &right2;
    Solution solution;
    vector<vector<int> > t = solution.levelOrder(NULL);
    cout << "vector.size(): " << t.size() << endl;
    cout << "[" << endl;
    vector<vector<int> >::iterator it = t.begin();
    while(it != t.end()) {
        cout << "  [";
        vector<int> tmp = *it++;
        vector<int>::iterator it_tmp = tmp.begin();
        while(it_tmp != tmp.end()) {
            cout << *it_tmp++ << " ";
        }
        cout << "]" << endl;
    }
    cout << endl << "]" << endl;
    return 0;
}
