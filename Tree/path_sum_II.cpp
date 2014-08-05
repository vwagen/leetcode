#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        vector<int> stack;
        if(root == NULL) {
            return ret;
        }
        else {
            doHasPathSum(root, sum, ret, stack);
        }
    }
    int doHasPathSum(TreeNode* root, int sum, vector<vector<int> > &ret, vector<int> &stack) {
        stack.push_back(root -> val);
        if((sum - root -> val == 0) && (root -> left == NULL && root -> right == NULL)) {
            ret.push_back(stack);
        }
        if(root -> left) {
            doHasPathSum(root -> left, sum - root -> val, ret, stack);
        }
        if(root -> right) {
            doHasPathSum(root -> right, sum - root -> val, ret, stack);
        }
        stack.pop_back();
        return 0;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(7);
    Solution s;
    vector<vector<int> > ret = s.pathSum(root, 9);
    for(int i = 0; i < ret.size(); i++) {
        for(int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
