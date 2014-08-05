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
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        int sum = root -> val;
        sum = left > 0 ? sum + left : sum;
        sum = right > 0 ? sum + right : sum;
        max_sum = max_sum >= sum ? max_sum : sum;
        int max_side = left > right ? left : right;
        return max_side > 0 ? root -> val + max_side : root -> val;
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
    cout << "maximum: " << s.maxPathSum(root) << endl;
    return 0;
}
