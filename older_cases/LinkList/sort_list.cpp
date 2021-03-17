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
    ListNode *mergeSort(ListNode* head, ListNode* tail) {
        if(head == tail) {
            tail -> next = NULL;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(1) {
            if(fast == tail) {
                break;
            }
            fast = fast -> next;
            if(fast == tail) {
                break;
            }
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* merge_right = mergeSort(slow -> next, fast);
        ListNode* merge_left = mergeSort(head, slow);
        if(merge_right -> val < merge_left -> val) {
            head = merge_right;
        }
        else {
            head = merge_left;
        }
        while(merge_right != NULL && merge_left != NULL) {
            if(merge_right -> val < merge_left -> val) {
                while(merge_right -> next != NULL && merge_right -> next -> val <= merge_left -> val) {
                    merge_right = merge_right -> next;
                }
                ListNode* tmp = merge_right -> next;
                merge_right -> next = merge_left;
                merge_right = tmp;
            }
            else {
                while(merge_left -> next != NULL && merge_left -> next -> val <= merge_right -> val) {
                    merge_left = merge_left -> next;
                }
                ListNode* tmp = merge_left -> next;
                merge_left -> next = merge_right;
                merge_left = tmp;
            }
        }
        return head;
    }
    ListNode *sortList(ListNode *head) {
        if(head != NULL) {
            ListNode* tail = head;
            while(tail -> next != NULL) {
                tail = tail -> next;
            }
            head = mergeSort(head, tail);
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    //int A[17] = {2, 1, 3, 0, 8, 4, 5, 2, 1, 1, 1, 1, 1, 9, 3, 7, 9};
    //int n = 17;
    int A[5] = {1,2,3,1,2};
    int n = 5;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.sortList(head);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
