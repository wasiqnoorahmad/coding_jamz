
#include "common.hpp"

#include <iostream>

void p_vector(std::vector<int> &A) {
  for (int v : A) {
    printf("%d, ", v);
  }
  printf("\n");
}

void insert_node(ListNode *head, int val) {
  ListNode *walk = head;
  while (walk->next)
    walk = walk->next;
  walk->next = new ListNode(val);
}

void p_list(ListNode *head) {
  ListNode *walk = head;
  while (walk) {
    printf("%d -> ", walk->val);
    walk = walk->next;
  }
  printf("\n");
}