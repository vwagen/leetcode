#include "utils.hh"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode mega(0, head);
        ListNode *l_node = &mega;
        int count = 1;
        while (l_node->next && count < left)
        {
            l_node = l_node->next;
            count++;
        }
        ListNode *r_node = l_node->next;
        while (r_node && r_node->next && count < right)
        {
            r_node = r_node->next;
            count++;
        }
        ListNode *new_next = r_node->next;
        ListNode *node_to_be_modified = l_node->next;
        while (node_to_be_modified != r_node)
        {
            ListNode *old_next = node_to_be_modified->next;
            node_to_be_modified->next = new_next;
            new_next = node_to_be_modified;
            node_to_be_modified = old_next;
        }
        node_to_be_modified->next = new_next;
        l_node->next = node_to_be_modified;
        return mega.next;
    }

    ListNode *reverseBetween_better(ListNode *head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        ListNode* tail = head;
        ListNode* l_node = nullptr;
        ListNode* new_next = nullptr;
        ListNode* new_head = head;
        int count = 1;
        while (count < right)
        {
            ListNode* old_next = new_head->next;
            if (count >= left)
            {
                new_head->next = new_next;
            }
            else
            {
                l_node = tail;
                tail = tail->next;
            }
            new_next = new_head;
            new_head = old_next;
            count++;
        }
        tail->next = new_head->next;
        new_head->next = new_next;
        if (l_node)
        {
            l_node->next = new_head;
        }
        else
        {
            head = new_head;
        }
        return head;
    }

    ListNode *reverseBetween_best(ListNode *head, int left, int right)
    {
        ListNode dummy(0, head);
        ListNode* guard = &dummy;
        ListNode* point = dummy.next;
        int count = 1;
        while (count < left)
        {
            guard = guard->next;
            point = point->next;
            count++;
        }
        for (int i = 0; i < right - left; ++i)
        {
            ListNode* tmp = point->next;
            point->next = tmp->next;
            tmp->next = guard->next;
            guard->next = tmp;
        }
        return dummy.next;
    }
};

int main(int argc,char *argv[])
{
    Solution solution;
    std::vector<int> v = {1,2,3,4,5};
    int left = 2;
    int right = 4;
    ListNode* l = gen_list_nodes(v);
    print_list_nodes(l);

    ListNode* ret = solution.reverseBetween_best(l, left, right);
    print_list_nodes(ret);

    free_list_nodes(l);

    fflush(stdout);
    return 0;
}
