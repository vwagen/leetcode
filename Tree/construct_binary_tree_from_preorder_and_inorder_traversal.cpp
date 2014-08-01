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
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        return doBuildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* doBuildTree(vector<int> &preorder, int preorder_head, int preorder_tail, vector<int> &inorder, int inorder_head, int inorder_tail) {
        if(inorder_head > inorder_tail || preorder_head > preorder_tail) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preorder_head]);
        int i;
        for(i = inorder_head; i <= inorder_tail; i++) {
            if(inorder[i] == preorder[preorder_head]) {
                break;
            }
        }
        root -> left = doBuildTree(preorder, preorder_head + 1, preorder_head + (i - inorder_head), inorder, inorder_head, i - 1);
        root -> right = doBuildTree(preorder, preorder_tail - (inorder_tail - i) + 1, preorder_tail, inorder, i + 1, inorder_tail);
        return root;
    }
};

int preOrder(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    cout << root -> val << " ";
    preOrder(root -> left);
    preOrder(root -> right);
    return 0;
}

int inOrder(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    inOrder(root -> left);
    cout << root -> val << " ";
    inOrder(root -> right);
    return 0;
}

int main(int argc, char* argv[]) {
    vector<int> preorder;
    vector<int> inorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(3);
    preorder.push_back(5);
    preorder.push_back(7);
    inorder.push_back(3);
    inorder.push_back(2);
    inorder.push_back(1);
    inorder.push_back(5);
    inorder.push_back(7);
    cout << "Begin" << endl;
    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    return 0;
}
