#include "sorting.hh"

class Solution
{
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode mega(0, head);
        ListNode *cur, *tail = &mega;
        while (cur = tail->next)
        {
            ListNode* it = &mega;
            while (it->next != tail->next && it->next->val < cur->val)
            {
                it = it->next;
            }
            tail->next = cur->next;
            cur->next = it->next;
            it->next = cur;
            tail = tail->next == cur ? cur : tail;
        }
        return mega.next;
    }

    ListNode* insertionSortList_better(ListNode* head) {
        ListNode *arr[10001] = {nullptr};
        while (head)
        {
            ListNode* next = head->next;
            head->next = arr[head->val + 5000];
            arr[head->val + 5000] = head;
            head = next;
        }
        ListNode mega;
        ListNode* tail = &mega;
        for (int i = 0; i < 10001; i++)
        {
            if (arr[i])
            {
                tail->next = arr[i];
            }
            while (tail->next)
            {
                tail = tail->next;
            }
        }
        return mega.next;
    }
};

void run_insertion_sort_list_147()
{
    Solution solution;
    std::vector<int> v = {-1, 5, 3, 4, 0};
    ListNode* l = gen_list_nodes(v);
    print_list_nodes(l);

    ListNode* ret = solution.insertionSortList_better(l);
    print_list_nodes(ret);

    free_list_nodes(l);
}
