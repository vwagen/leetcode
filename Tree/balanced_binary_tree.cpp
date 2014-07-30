#include <iostream>
#include <stack>
#include <climits>
using namespace std;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    typedef struct {
        int level;
        TreeNode* node;
    } Level;
    bool isBalanced(TreeNode* root) {
        stack<Level> nodes;
        int max = 0;
        int min = INT_MAX;
        if(root == NULL) {
            return true;
        }
        Level root_level = {1, root};
        //Use preorder traversal to get the leaf levels.
        while(root_level.node != NULL) {
            nodes.push(root_level);
            if(root_level.node -> left == NULL && root_level.node -> right == NULL) {
                max = max < root_level.level ? root_level.level : max;
                min = min > root_level.level ? root_level.level : min;
            }
            root_level.level++;
            root_level.node = root_level.node -> left;
            while(nodes.size() > 0 && root_level.node == NULL) {
                root_level = nodes.top();
                nodes.pop();
                root_level.level++;
                root_level.node = root_level.node -> right;
            }
        }
        cout << "max: " << max << " min: " << min << endl;
        if(max > min + 1) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> right = new TreeNode(3);
    Solution s;
    cout << "Result: " << s.isBalanced(root) << endl;
    return 0;
}
