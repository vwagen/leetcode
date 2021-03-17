#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

typedef struct RandomListNode {
    int label;
    RandomListNode *next, *random; 
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}  
} Node;

int print_list_node(Node *head){
    while(head != NULL) {
        if(head -> next != NULL) {
            cout << head -> label << " -> ";
        }
        else {
            cout << head -> label;
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
    map<int, RandomListNode*> labels;
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* new_head = NULL;
        if(head != NULL && (labels.find(head -> label) == labels.end())) {
            new_head = new RandomListNode(head -> label);
            labels[head -> label] = new_head;
            new_head -> next = copyRandomList(head -> next);
            new_head -> random = copyRandomList(head -> random);
            return new_head;
        }
        else if(head == NULL) {
            return NULL;
        }
        else {
            return labels[head -> label];
        }
    }
};

int main(int argc, char* argv[]) {
    int A[5] = {1, 1, 2, 2, 3};
    int n = 5;
    cout << "A[] is: " << endl;
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << endl;
    Node* head = make_list_from_array(A, n);
    cout << "List of this array is :" << endl;
    print_list_node(head);
    Solution s;
    head = s.copyRandomList(head);
    cout << "After process List is :" << endl;
    print_list_node(head);
    return 0;
}
