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
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        return doBuildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* doBuildTree(vector<int> &postorder, int postorder_head, int postorder_tail, vector<int> &inorder, int inorder_head, int inorder_tail) {
        if(inorder_head > inorder_tail || postorder_head > postorder_tail) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postorder_tail]);
        int i;
        for(i = inorder_head; i <= inorder_tail; i++) {
            if(inorder[i] == postorder[postorder_tail]) {
                break;
            }
        }
        root -> left = doBuildTree(postorder, postorder_tail - (inorder_tail - i) - (i - inorder_head), postorder_tail - (inorder_tail - i) - 1, inorder, inorder_head, i - 1);
        root -> right = doBuildTree(postorder, postorder_tail - (inorder_tail - i), postorder_tail - 1, inorder, i + 1, inorder_tail);
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
    vector<int> postorder;
    vector<int> inorder;
    //postorder.push_back(3);
    //postorder.push_back(2);
    //postorder.push_back(7);
    //postorder.push_back(5);
    //postorder.push_back(1);
    //inorder.push_back(3);
    //inorder.push_back(2);
    //inorder.push_back(1);
    //inorder.push_back(5);
    //inorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(2);
    postorder.push_back(1);
    inorder.push_back(1);
    inorder.push_back(3);
    inorder.push_back(2);
    cout << "Begin" << endl;
    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    return 0;
}
