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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* last_node = head;
        ListNode* node_less_than_x;
        if(head -> val < x) {
            node_less_than_x = head;
        }
        else {
            node_less_than_x = NULL;
        }
        ListNode* tmp = head -> next;
        while(tmp != NULL) {
            if(tmp -> val < x) {
                if(last_node == node_less_than_x) {
                    last_node = tmp;
                    node_less_than_x = tmp;
                    tmp = tmp -> next;
                    continue;
                }
                last_node -> next = tmp -> next;
                if(node_less_than_x == NULL) {
                    tmp -> next = head;
                    head = tmp;
                }
                else{
                    tmp -> next = node_less_than_x -> next;
                    node_less_than_x -> next = tmp;
                }
                node_less_than_x = tmp;
                tmp = last_node -> next;
            }
            else {
                last_node = tmp;
                tmp = tmp -> next;
            }
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    //int A[6] = {1, 4, 3, 2, 5, 2};
    //int n = 6;
    int A[2] = {2, 1};
    int n = 2;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.partition(head, 3);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
