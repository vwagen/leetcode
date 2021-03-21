#include "utils.hh"
#include <algorithm>

void print_int_vector(std::vector<int>& v)
{
    for (int & i : v)
    {
        printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);
}

void print_intervals(const std::vector<std::vector<int>>& v)
{
    printf("[");
    for (int i = 0; i < v.size(); i++)
    {
        printf("[%d, %d]%s", v[i][0], v[i][1], i < v.size() - 1 ? ", " : "");
    }
    printf("]\n");
    fflush(stdout);
}

ListNode *gen_list_nodes(std::vector<int> &v)
{
    ListNode *ret = nullptr;
    std::reverse(v.begin(), v.end());
    for (int i : v)
    {
        ListNode *new_node = new ListNode(i);
        new_node->next = ret;
        ret = new_node;
    }
    return ret;
}

void free_list_nodes(ListNode *l)
{
    while (l)
    {
        ListNode *l_tmp = l->next;
        delete l;
        l = l_tmp;
    }
}

void print_list_nodes(ListNode *l)
{
    while (l)
    {
        printf("%d%s", l->val, l->next ? ", " : "");
        l = l->next;
    }
    printf("\n");
    fflush(stdout);
}

