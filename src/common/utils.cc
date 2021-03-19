#include "utils.hh"

void print_int_vector(std::vector<int>& v)
{
    for (int & i : v)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void print_intervals(const std::vector<std::vector<int>>& v)
{
    printf("[");
    for (int i = 0; i < v.size(); i++)
    {
        printf("[%d, %d]%s", v[i][0], v[i][1], i < v.size() - 1 ? ", " : "");
    }
    printf("]\n");
}

