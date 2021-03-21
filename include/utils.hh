#pragma once

#include "list_node.hh"

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

void print_int_vector(std::vector<int>& v);
void print_intervals(const std::vector<std::vector<int>>& v);

ListNode *gen_list_nodes(std::vector<int> &v);
void free_list_nodes(ListNode *l);
void print_list_nodes(ListNode *l);
