/* This program is about rotating a linked list */

#include <bits/stdc++.h>

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
} ListNode;

void insert(ListNode *head, int val) {
  if (head == NULL) {
    head = new ListNode(val);
    return;
  }

  ListNode *walk = head;
  while (walk->next != NULL)
    walk = walk->next;
  walk->next = new ListNode(val);
}

void display(ListNode *head) {
  ListNode *walk = head;
  while (walk != NULL) {
    printf("%d -> ", walk->val);
    walk = walk->next;
  }
  printf("\n");
}

ListNode *rotate(ListNode *head, int k) {
  if (head == NULL || head->next == NULL || k == 0)
    return head;

  /* Make a circular list first */
  int size = 1;
  ListNode *last = head;
  while (last->next != NULL) {
    last = last->next;
    size++;
  }
  if (k % size == 0)
    return head;
  last->next = head;

  ListNode *k_node = head;
  int steps = 0;
  while (steps < k % size) {
    k_node = k_node->next;
    steps++;
  }

  /* Rest to normal list */
  last->next = NULL;

  ListNode *walk = head;
  while (k_node->next != NULL) {
    k_node = k_node->next;
    walk = walk->next;
  }

  /* Walk is the last node */
  ListNode *after = walk->next;
  walk->next = NULL;
  k_node->next = head;

  return after;
}

int main(int argc, char const *argv[]) {
  ListNode *head = new ListNode(1);
  insert(head, 2);
  insert(head, 3);

  display(head);
  ListNode *new_head = rotate(head, 2000000000);
  display(new_head);
  return 0;
}
