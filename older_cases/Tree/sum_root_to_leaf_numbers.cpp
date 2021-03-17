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
    int sumNumbers(TreeNode* root) {
        vector<int> stack;
        sum = 0;
        if(root != NULL) {
            doSumNumbers(root, stack);
        }
        return sum;
    }
private:
    int sum;
    int doSumNumbers(TreeNode* root, vector<int> &stack) {
        stack.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            for(int i = stack.size() - 1, j = 1; i >= 0; i--, j *= 10) {
                sum += stack[i] * j;
            }
        }
        if(root -> left) {
            doSumNumbers(root -> left, stack);
        }
        if(root -> right) {
            doSumNumbers(root -> right, stack);
        }
        stack.pop_back();
        return 0;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(7);
    Solution s;
    cout << "result: " << s.sumNumbers(root) << endl;
    return 0;
}
