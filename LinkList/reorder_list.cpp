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
    void reorderList(ListNode *head) {
        if(head == NULL) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next;
            if(fast -> next != NULL) {
                fast = fast -> next;
            }
            else {
                break;
            }
            slow = slow -> next;
        }
        reverse_nodes(slow -> next, fast);
        slow -> next = NULL;
        ListNode* next_node;
        while(head != NULL && fast != NULL) {
            next_node = head -> next;
            head -> next = fast;
            head = next_node;
            next_node = fast -> next;
            fast -> next = head;
            fast = next_node;
        }
        return;
    }
};

int main(int argc, char* argv[]) {
    int A[6] = {1,2,3,4,5,6};
    int n = 6;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Node* tmp = head;
    Solution s;
    s.reorderList(head);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
