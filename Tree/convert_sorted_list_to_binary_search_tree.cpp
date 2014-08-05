#include <iostream>
#include <stack>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
    LNode(int x) : val(x), next(NULL) {}
} ListNode;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* tmp = head;
        while(tmp) {
            len++;
            tmp = tmp -> next;
        }
        return buildBST(head, 0, len - 1);
    }
    TreeNode* buildBST(ListNode* &head, int left, int right) {
        if(left > right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* leftChild = buildBST(head, left, mid - 1);
        TreeNode* parent  = new TreeNode(head -> val);
        parent -> left = leftChild;
        head = head -> next;
        parent -> right = buildBST(head, mid + 1, right);
        return parent;
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
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    for(int i = 1; i <= 6; i++) {
        tmp -> next = new ListNode(i);
        tmp = tmp -> next;
    }
    tmp = head;
    while(tmp) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
    cout << endl;
    Solution s;
    TreeNode* root = s.sortedListToBST(head);
    traversal(root);
    cout << endl;
    return 0;
}
