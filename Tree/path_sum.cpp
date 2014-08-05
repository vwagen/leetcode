#include <iostream>
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        }
        if((sum - root -> val == 0) && (root -> left == NULL && root -> right == NULL)) {
            return true;
        }
        else if((sum - root -> val != 0) && (root -> left == NULL && root -> right == NULL)) {
            return false;
        }
        bool ret = false;
        if(root -> left) {
            ret = hasPathSum(root -> left, sum - root -> val);
        }
        if(root -> right && !ret) {
            ret = hasPathSum(root -> right, sum - root -> val);
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    Solution s;
    cout << "ret: " << s.hasPathSum(root, 9) << endl;
    return 0;
}
