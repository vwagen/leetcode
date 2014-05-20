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
    ListNode *reverseBetween(ListNode *head, int m, int n) {            
        ListNode* left_node = NULL;
        ListNode* right_node = NULL;
        ListNode* m_node = NULL;
        ListNode* n_node = NULL;
        ListNode* tmp = head;
        int k = 1;
        while(tmp != NULL && k < m) {
            left_node = tmp;
            tmp = tmp -> next;
            k++;
        }
        if(tmp == NULL) {
            return head;
        }
        m_node = tmp;
        ListNode* last_node = NULL;
        while(tmp != NULL && k <= n) {
            n_node = tmp;
            right_node = n_node -> next;
            tmp -> next = last_node;
            last_node = tmp;
            tmp = right_node;
            k++;
        }
        if(left_node == NULL) {
            head = n_node;
        }
        else {
            left_node -> next = n_node;
        }
        m_node -> next = right_node;
        return head;
    }
};

int main(int argc, char* argv[]) {
    int A[1] = {5};//, 2, 3, 4, 5};
    int n = 1;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.reverseBetween(head, 1, 1);
    cout << "After reverse :" << endl;
    print_list_node(head);
    return 0;
}
