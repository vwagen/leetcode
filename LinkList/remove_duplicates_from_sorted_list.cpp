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
    ListNode *deleteDuplicates(ListNode *head) {            
        ListNode* tmp = head;
        int tmp_val;
        while(tmp != NULL) {
            tmp_val = tmp -> val;
            while(tmp -> next != NULL && (tmp -> next) -> val == tmp_val) {
                tmp -> next = (tmp -> next) -> next;
            }
            tmp = tmp -> next;
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    int A[5] = {1, 1, 2, 2, 2};
    int n = 5;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.deleteDuplicates(head);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
