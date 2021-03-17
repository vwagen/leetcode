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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL || n == 0) {
            return head;
        }
        ListNode* fast = head;
        while(n-- > 0 && fast != NULL) {
            fast = fast -> next;
        }
        ListNode* slow = head;
        ListNode* last_slow = NULL;
        while(fast != NULL) {
            fast = fast -> next;
            last_slow = slow;
            slow = slow -> next;
        }
        if(last_slow == NULL) {
            head = head -> next;
        }
        else {
            last_slow -> next = slow -> next;
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    int A[1] = {1};//{1, 1, 2, 2, 3};
    int n = 1;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.removeNthFromEnd(head, 2);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
