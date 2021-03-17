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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* last_node = NULL;
        ListNode* left_node = NULL;
        ListNode* right_node = NULL;
        ListNode* tmp = head;
        int count;
        while(tmp != NULL && tmp -> next != NULL) {
            left_node = tmp;
            right_node = tmp -> next;
            count = 2;
            while(tmp != NULL && count != 0) {
                tmp = tmp -> next;
                count--;
            }
            if(last_node == NULL) {
                head = right_node;
            }
            else{
                last_node -> next = right_node;
            }
            right_node -> next = left_node;
            left_node -> next = tmp;
            last_node = left_node;
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    int A[3] = {1, 2, 3};//, 3, 4, 5};
    int n = 3;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.swapPairs(head);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
