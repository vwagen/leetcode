#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next; 
    ListNode(int x) : val(x), next(NULL) {}  
} Node;

int print_list_node(Node *head){
    while(head != NULL) {
        if(head -> next != NULL) {
            cout << head -> val << " -> ";
        }
        else {
            cout << head -> val;
        }
        head = head -> next;
    }
    cout << endl;
    return 0;
}

Node* make_list_from_array(int A[], int n) {
    if(n == 0) {
        return NULL;
    }
    Node* head = NULL;
    head = new Node(A[0]);
    Node* tmp = head;
    for(int i = 1; i < n; i++) {
        tmp -> next = new Node(A[i]);
        tmp = tmp -> next;
    }
    return head;
}

class Solution {
public:
    int reverse_nodes(ListNode *head, ListNode* tail) {            
        ListNode* last_node = NULL;
        ListNode* next_node = NULL;
        ListNode* tmp = head;
        tail -> next = NULL;
        while(tmp != NULL) {
            next_node = tmp -> next;
            tmp -> next = last_node;
            last_node = tmp;
            tmp = next_node;
        }
        return 0;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* left;
        ListNode* right;
        ListNode* last_node = NULL;
        ListNode* next_node = head;
        while(1) {
            left = next_node;
            right = next_node;
            int i = k;
            while(right != NULL && i-- > 1) {
                right = right -> next;
            }
            if(right == NULL) {
                break;
            }
            next_node = right -> next;
            reverse_nodes(left, right);
            if(last_node == NULL) {
                head = right;
            }
            else {
                last_node -> next = right;
            }
            left -> next = next_node;
            last_node = left;
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    int A[1] = {1};// {1, 2, 3, 4, 5};
    int n = 1;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.reverseKGroup(head, 0);
    cout << "After reverse :" << endl;
    print_list_node(head);
    return 0;
}
