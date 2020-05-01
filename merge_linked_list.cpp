/* This program merges two inked list. Description can be found at:
 * https://leetcode.com/problems/merge-two-sorted-lists/ */

#include <bits/stdc++.h>

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

void print_list(ListNode *root) {
  ListNode *walk = root;
  while (walk != NULL) {
    printf("%d -> ", walk->val);
    walk = walk->next;
  }
  printf("\n");
}

ListNode *merge(ListNode *l1, ListNode *l2) {
  if (l1 == NULL || l2 == NULL) return l1 == NULL ? l2 : l1;

  ListNode *left = l1, *right = l2;
  int tmp;

  while (left != NULL && right != NULL) {
    if (left->val < right->val) {
      left = left->next;
    } else if (left->val > right->val) {
      tmp = left->val;
      left->val = right->val;
      left->next = new ListNode(tmp, left->next);
      left = left->next;
      right = right->next;
    } else {
      left->next = new ListNode(left->val, left->next);
      left = left->next->next;
      right = right->next;
    }
  }

  if (right) {
    left = l1;
    while (left->next != NULL) left = left->next;
    left->next = right;
  }
  return l1;
}

int main(int argc, char const *argv[]) {
  /* First list */
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  l1->next->next->next = new ListNode(5);
  l1->next->next->next->next = new ListNode(6);

  /* First list */
  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);
  // l2->next->next->next = new ListNode(5);
  // l2->next->next->next->next = new ListNode(6);

  ListNode *merged = merge(l1, l2);
  print_list(merged);
  return 0;
}
