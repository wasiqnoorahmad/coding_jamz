/* This program swap nodes of a linked-list in pairs. Problem can be found at:
 * https://leetcode.com/problems/swap-nodes-in-pairs/ */

#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){};
} ListNode;

void print_list(ListNode *head) {
  ListNode *walk = head;
  while (walk != NULL) {
    printf("%d -> ", walk->val);
    walk = walk->next;
  }
  printf("\n");
}

ListNode *swap_pairs(ListNode *head) {
  if (head == NULL) return NULL;
  if (head->next == NULL) return head;

  ListNode *left = head, *right = head->next, *tail, *new_head = NULL,
           *prev = NULL;

  while (left && right) {
    tail = right->next;

    left->next = tail;
    right->next = left;
    if (prev) prev->next = right;

    if (!new_head) new_head = right;

    if (tail) {
      prev = left, left = tail, right = tail->next;
    } else {
      break;
    }
  }
  return new_head;
}

int main(int argc, char const *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  print_list(head);
  ListNode *new_head = swap_pairs(head);
  print_list(new_head);

  return 0;
}
