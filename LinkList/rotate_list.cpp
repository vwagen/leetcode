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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* tail = head;
        int all_num = 1;
        while(tail -> next != NULL) {
            tail = tail -> next;
            all_num++;
        }
        tail -> next = head;
        ListNode* tmp = head;
        for(int i = 1; i < (all_num - (k % all_num)); i++) {
            tmp = tmp -> next;
        }
        head = tmp -> next;
        tmp -> next = NULL;
        return head;
    }
};

int main(int argc, char* argv[]) {
    int A[2] = {1, 2};
    int n = 2;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.rotateRight(head, 15);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
