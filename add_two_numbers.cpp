#include <iostream>
using namespace std;

struct ListNode { 
    int val; 
    ListNode *next; 
    ListNode(int x) : val(x), next(NULL) {} 
}; 

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if(l2 == NULL) {
                return l1;        
            }        
            if(l1 == NULL && l2 != NULL) {
                return l2;
            }
            ListNode* l1_tmp = l1;        
            ListNode* l2_tmp = l2;        
            ListNode* ret = l1;
            int sum_tmp = 0;        
            while(l2 != NULL || sum_tmp > 9) {
                if(l1 == NULL && l2 == NULL) {
                    l1_tmp -> next = append;
                    break;
                }
                if(l1 == NULL && l2 != NULL) {
                    l1_tmp -> next = l2;
                    l2_tmp -> next = NULL;
                    l1 = l1_tmp -> next;
                    l2 = l2_tmp -> next;
                }
                if(l1 != NULL && l2 == NULL) {
                    sum_tmp = l1 -> val + (sum_tmp / 10);
                    l1 -> val = sum_tmp % 10;
                    l1_tmp = l1;
                    l1 = l1_tmp -> next;
                    continue;
                }
                sum_tmp = l1 -> val + l2 -> val + (sum_tmp / 10);
                l1 -> val = sum_tmp % 10;
                l1_tmp = l1;
                l1 = l1_tmp -> next;
                l2_tmp = l2;
                l2 = l2_tmp -> next;
            }
            return ret;
        }
        Solution() {
            append = new ListNode(1);
        }
        ~Solution() {
            delete(append);
        }
        ListNode* append;
};

int main(int argc, char* argv[]) {
    int a[] = {1,2,3};
    int b[] = {2,3,4};
    int i;
    ListNode* tmp;
    //for() {}
    return 0;
}
