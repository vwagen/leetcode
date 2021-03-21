#include "sorting.hh"

class Solution
{
public:
    /* Bubble Sort, TLE(Time Limit Exceeded). */
    /*
    ListNode* sortList(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *cur = dummy.next, *prev = &dummy, *tail = nullptr;
        while (cur != tail)
        {
            while (cur->next != tail)
            {
                if (cur->val > cur->next->val)
                {
                    prev->next = cur->next;
                    cur->next = cur->next->next;
                    prev->next->next = cur;
                }
                else
                {
                    cur = cur->next;
                }
                prev = prev->next;
            }
            tail = cur;
            cur = dummy.next;
            prev = &dummy;
        }
        return dummy.next;
    }
    */

    /* Merge Sort, up-to-bottom. */
    /* Tips: 找链表的中点用快慢双指针。*/
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }

        /* Find the middle node. */
        ListNode dummy(0, head);
        ListNode *slow = &dummy, *fast = &dummy;
        /* N.B. If the fast points to the last node, stop looping. */
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : fast;
        }

        /* Sort the divided lists. */
        ListNode* head_2 = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        head_2 = sortList(head_2);

        /* Merge the sorted lists. */
        dummy.next = nullptr;
        ListNode* cur = &dummy;
        while (head || head_2)
        {
            ListNode **p_target = !head_2 || (head && head->val < head_2->val) ? &head : &head_2;
            cur->next = *p_target;
            cur = cur->next;
            *p_target = head && head_2 ? (*p_target)->next : nullptr;
        }
        return dummy.next;
    }

    /* Merge Sort, bottom-to-up. */
    ListNode* sortList_best(ListNode *head) {
        struct head_and_tail
        {
            ListNode *head;
            ListNode *tail;
            head_and_tail(ListNode *x, ListNode *y) : head(x), tail(y) {};
        };

        auto merge = [](ListNode *l1, ListNode *l2)
        {
            ListNode dummy;
            ListNode *cur = &dummy;
            while (l1 || l2)
            {
                ListNode **p_target = !l2 || (l1 && l1->val < l2->val) ? &l1 : &l2;
                cur->next = *p_target;
                cur = cur->next;
                *p_target = l1 && l2 ? (*p_target)->next : nullptr;
            }
            while (cur && cur->next)
            {
                cur = cur->next;
            }
            return head_and_tail(dummy.next, cur);
        };

        auto split = [](ListNode *l, int n)
        {
            ListNode dummy(0, l);
            ListNode* cur = &dummy;
            while (n > 0 && cur->next)
            {
                cur = cur->next;
                n--;
            }
            ListNode* tmp = cur->next;
            cur->next = nullptr;
            return tmp;
        };

        int total = 0;
        ListNode* t = head;
        while (t)
        {
            total++;
            t = t->next;
        }

        ListNode dummy(0, head);
        ListNode *prev = &dummy, *cur_head = dummy.next;
        int step_nodes = 2;
        while (step_nodes / 2 <= total)
        {
            do
            {
                ListNode *next_list = split(cur_head, step_nodes);
                ListNode *r_list = split(cur_head, step_nodes / 2);
                head_and_tail ht = merge(cur_head, r_list);
                prev->next = ht.head;
                prev = ht.tail;
                prev->next = next_list;
                cur_head = next_list;
            } while (cur_head);
            step_nodes *= 2;
            prev = &dummy;
            cur_head = dummy.next;
        }
        return dummy.next;
    }
};

void run_sort_list_148()
{
    Solution solution;
    std::vector<int> v = {-1, 5, 3, 4, 0};
    ListNode* l = gen_list_nodes(v);
    print_list_nodes(l);

    ListNode* ret = solution.sortList_best(l);
    print_list_nodes(ret);

    free_list_nodes(l);
}
