#include <iostream>
#include <stack>
using namespace std;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;
typedef struct LinkNode{
    struct LinkNode* left;
    struct LinkNode* right;
    struct LinkNode* next;
} TreeLinkNode;

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if(root == NULL) {
            return;
        }
        while(root) {
            TreeLinkNode* next = NULL;           // First node of next level.
            TreeLinkNode* prev = NULL;           // Previours node of same level.
            for(; root; root = root -> next) {   // Root will move in the same level. In current level, every node is point to next node.
                if(next == NULL) {               // If next points to NULL, intialize it.
                    next = root -> left != NULL ? root -> left : root -> right;
                }
                if(root -> left != NULL) {
                    if(prev != NULL) {           // If there is a previours node, make its next point to root -> left;
                        prev -> next = root -> left;
                    }
                    prev = root -> left;
                }
                if(root -> right != NULL) {
                    if(prev != NULL) {           // If there is a previours node, make its next point to root -> right;
                        prev -> next = root -> right;
                    }
                    prev = root -> right;
                }
            }
            root = next;                         // Root change to next level.
        }
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
    return 0;
}
