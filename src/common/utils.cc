#include "utils.hh"

void print_int_vector(std::vector<int>& v)
{
    for (int & i : v)
    {
        printf("%d ", i);
    }
    printf("\n");
}
