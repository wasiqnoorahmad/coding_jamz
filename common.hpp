#ifndef COMMON_H
#define COMMON_H

#include <vector>

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

void p_vector(std::vector<int> &A);
void insert_node(ListNode *head, int val);
void p_list(ListNode *head);

#endif