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
    void flatten(TreeNode* root) {
        doFlatten(root);
    }
    TreeNode* doFlatten(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        /************************************************************************************/
        /***************** Flatten left sub-tree and right sub-tree first. ******************/
        /********************** left_tail is the tail of left sub-tree **********************/
        /********************* right_tail is the tail of right sub-tree *********************/
        TreeNode* left_tail = doFlatten(root -> left);
        TreeNode* right_tail = doFlatten(root -> right);
        /************************************************************************************/

        if(left_tail == NULL && right_tail == NULL) {
            return root;
        }
        else if(left_tail == NULL && right_tail != NULL) {
            return right_tail;
        }
        else if(left_tail != NULL && right_tail == NULL) {
            root -> right = root -> left;
            root -> left = NULL;
            return left_tail;
        }
        else {
            left_tail -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
            return right_tail;
        }
    }
};

// This Function is for Testing printing
int preTraversal(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    cout << root -> val << " ";
    preTraversal(root -> left);
    preTraversal(root -> right);
    return 0;
}

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    //root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    //root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    Solution s;
    s.flatten(root);
    preTraversal(root);
    cout << endl;
    return 0;
}
