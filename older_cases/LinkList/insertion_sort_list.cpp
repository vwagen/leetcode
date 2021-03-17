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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL) {
            return head;
        }
        ListNode* sorted_head = insertionSortList(head -> next);
        ListNode* last_node = NULL;
        ListNode* tmp = sorted_head;
        while(tmp != NULL && head -> val > tmp -> val) {
            last_node = tmp;
            tmp = tmp -> next;
        }
        if(last_node == NULL) {
            head -> next = sorted_head;
        }
        else {
            head -> next = last_node -> next;
            last_node -> next = head;
            head = sorted_head;
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    //int A[17] = {2, 1, 3, 0, 8, 4, 5, 2, 1, 1, 1, 1, 1, 9, 3, 7, 9};
    //int n = 17;
    int A[3] = {1,1,1};
    int n = 3;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.insertionSortList(head);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
