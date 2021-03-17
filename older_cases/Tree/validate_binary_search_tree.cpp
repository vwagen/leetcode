#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    bool isValidBST(TreeNode* root) {  // Based on Morris inorder traversal. Time complexity: O(n). Space complexity: O(n).
        vector<int> morris_ret = morris_inorder_traversal(root);
        bool ret = true;
        for(int i = 0; i < (int)morris_ret.size() - 1; i++) {
            if(morris_ret[i] >= morris_ret[i + 1]) {
                ret = false;
                break;
            }
        }
        return ret;
    }
    vector<int> morris_inorder_traversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while(cur != NULL) {
            if(cur -> left == NULL) {
                ret.push_back(cur -> val);
                cur = cur -> right;
                continue;
            }
            prev = cur -> left;
            while(prev -> right != NULL && prev -> right != cur) {
                prev = prev -> right;
            }
            if(prev -> right == NULL) {
                prev -> right = cur;
                cur = cur -> left;
            }
            else {
                ret.push_back(cur -> val);
                prev -> right = NULL;
                cur = cur -> right;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(0);
    //root -> right = new TreeNode(6);
    //root -> left -> left = new TreeNode(1);
    //root -> left -> right = new TreeNode(3);
    //root -> right -> left = new TreeNode(5);
    //root -> right -> right = new TreeNode(7);
    Solution s;
    cout << "ret: " << s.isValidBST(root) << endl;
    return 0;
}
