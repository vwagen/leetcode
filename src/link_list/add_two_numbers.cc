#include "link_list.hh"
#include <algorithm>

void print_list_nodes(ListNode* l)
{
    std::string s;
    while (l)
    {
        s += (l->val + '0');
        l = l->next;
    }
    std::reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l1_origin = l1;
    ListNode* l2_origin = l2;
    ListNode* ret;
    int sum = 0;
    while (l1 || l2)
    {
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + sum / 10;
        l1 ? l1->val = sum % 10 : 0;
        l2 ? l2->val = sum % 10 : 0;
        ret = l1 ? l1_origin : l2_origin;

        if (l1 && l1->next == nullptr && (sum / 10))
        {
            l1->next = new ListNode(sum / 10);
            l1 = l1->next;
        }

        if (l2 && l2->next == nullptr && (sum / 10))
        {
            l2->next = new ListNode(sum / 10);
            l2 = l2->next;
        }

        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return ret;
}

ListNode* gen_list_nodes(std::string& num)
{
    ListNode* ret = nullptr;
    for (char c : num)
    {
        ListNode* new_node = new ListNode(c - '0');
        new_node->next = ret;
        ret = new_node;
    }
    return ret;
}

void free_list_nodes(ListNode* l)
{
    while (l)
    {
        ListNode* l_tmp = l->next;
        delete l;
        l = l_tmp;
    }
}

void run_add_two_numbers_case()
{
    std::string num1 = "942";
    std::string num2 = "9465";
    ListNode* l1 = gen_list_nodes(num1);
    ListNode* l2 = gen_list_nodes(num2);
    print_list_nodes(l1);
    print_list_nodes(l2);

    ListNode* ret = addTwoNumbers(l1, l2);
    print_list_nodes(ret);

    free_list_nodes(l1);
    free_list_nodes(l2);
}
