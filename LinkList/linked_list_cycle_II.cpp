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
    bool hasCycle(ListNode* &fast, ListNode* &slow) {
        while(slow != NULL) {
            fast = fast -> next;
            if(fast == NULL) {
                break;
            }
            fast = fast -> next;
            if(fast == NULL) {
                break;
            }
            slow = slow -> next;
            if(slow == fast) {
                return true;
            }

        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool has_cycle = hasCycle(fast, slow);
        if(has_cycle == true) {
            ListNode* find_node = head;
            while(find_node != slow) {
                slow = slow -> next;
                find_node = find_node -> next;
            }
            return find_node;
        }
        else {
            return NULL;
        }
    }
};

int main(int argc, char* argv[]) {
    int A[5] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Node* tmp = head;
    while(tmp != NULL && tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    cout << "tmp -> val: " << tmp -> val << endl;
    tmp -> next = head -> next;
    Solution s;
    ListNode* find_node = s.detectCycle(head);
    //cout << "After process List is :" << endl;
    //print_list_node(head);
    if(find_node != NULL) {
        cout << "Has cycle node:" << find_node -> val << endl;
    }
    else {
        cout << "No cycle!" << endl;
    }
    return 0;
}
