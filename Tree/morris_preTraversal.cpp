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
    vector<int> preTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while(cur != NULL) {
            if(cur -> left == NULL) {
                ret.push_back(cur -> val);
                cur = cur -> right;
                // Remenber to add continue;
                continue;
            }
            prev = cur -> left;
            while(prev -> right != NULL && prev -> right != cur) {
                prev = prev -> right;
            }
            if(prev -> right == NULL) {
                ret.push_back(cur -> val);
                prev -> right = cur;
                cur = cur -> left;
            }
            else if(prev -> right == cur) {
                prev -> right = NULL;
                cur = cur -> right;
            }
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
    vector<int> ret = s.preTraversal(root);
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
