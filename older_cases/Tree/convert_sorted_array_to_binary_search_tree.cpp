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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, (int)num.size() - 1);
    }
    TreeNode* buildBST(vector<int> &num, int left, int right) {
        if(left > right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root -> left = buildBST(num, left, mid - 1);
        root -> right = buildBST(num, mid + 1, right);
        return root;
    }
};

int traversal(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    traversal(root -> left);
    cout << root -> val << " ";
    traversal(root -> right);
    return 0;
}

int main(int argc, char* argv[]) {
    vector<int> num;
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    Solution s;
    TreeNode* ret = s.sortedArrayToBST(num);
    traversal(ret);
    cout << endl;
    return 0;
}
