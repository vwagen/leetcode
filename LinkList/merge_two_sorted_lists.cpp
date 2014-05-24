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
    ListNode *mergeTwoLists(ListNode *merge_left, ListNode *merge_right) {
        if(merge_left == NULL && merge_right == NULL) {
            return NULL;
        }
        if(merge_left == NULL && merge_right != NULL) {
            return merge_right;
        }
        else if(merge_left != NULL && merge_right == NULL) {
            return merge_left;
        }
        ListNode* head;
        if(merge_right -> val < merge_left -> val) {
            head = merge_right;
        }
        else {
            head = merge_left;
        }
        print_list_node(head);
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
};

int main(int argc, char* argv[]) {
    int A1[7] = {1, 2, 2, 4, 5, 7, 9};
    int n1 = 7;
    int A[5] = {2,3,6,7,8};
    int n = 5;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* merge_left = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(merge_left);

    cout << "A1[] is: " << endl;
    copy(A1, A1+n1, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* merge_right = make_list_from_array(A1, n1);
    cout << "List of this array is :" << endl;
    print_list_node(merge_right);

    Solution s;
    Node* head = s.mergeTwoLists(merge_left, merge_right);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
