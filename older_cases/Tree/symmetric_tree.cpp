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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        if((root -> left == NULL && root -> right != NULL) 
                || (root -> left != NULL && root -> right == NULL)) {
            return false;
        }
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        // mirror reverses right tree first.
        mirror_tree(right);
        //check the left tree and right tree are the same.
        bool ret = same_tree(left, right);
        // recover right tree.
        mirror_tree(right);
        return ret;
    }
    bool same_tree(TreeNode* left_root, TreeNode* right_root) {
        stack<TreeNode*> left_nodes, right_nodes;
        while(left_root != NULL && right_root != NULL) {
            left_nodes.push(left_root);
            right_nodes.push(right_root);
            if(left_root -> val != right_root -> val) {
                return false;
            }
            left_root = left_root -> left;
            right_root = right_root -> left;
            while(left_nodes.size() > 0 && left_root == NULL && right_nodes.size() > 0 && right_root == NULL) {
                left_root = left_nodes.top();
                left_nodes.pop();
                left_root = left_root -> right;
                right_root = right_nodes.top();
                right_nodes.pop();
                right_root = right_root -> right;
            }
        }
        if((left_root == NULL && right_root != NULL) 
                || (left_root != NULL && right_root == NULL)) {
            return false;
        }
        return true;
    }
    int mirror_tree(TreeNode* root) {
        stack<TreeNode*> nodes;
        while(root != NULL) {
            nodes.push(root);
            TreeNode* tmp = root -> left;
            root -> left = root -> right;
            root -> right = tmp;
            root = root -> left;
            while(nodes.size() > 0 && root == NULL) {
                root = nodes.top();
                nodes.pop();
                root = root -> right;
            }
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
