/* This program adds two linked list given at:
 * https://leetcode.com/problems/add-two-numbers/ */

#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
} ListNode;

void push(ListNode *root, ListNode *other) {
  ListNode *walk = root;
  while (walk->next != NULL)
    walk = walk->next;
  walk->next = other;
}

ListNode *with_carry(ListNode *l1, ListNode *l2, int carry = 0) {
  if (l1 == l2 && carry == 0)
    return NULL;

  int sum = carry;

  if (l1)
    sum += l1->val;
  if (l2)
    sum += l2->val;

  ListNode *result = new ListNode(sum % 10);
  if (l1 || l2) {
    ListNode *next =
        with_carry(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next,
                   sum >= 10 ? 1 : 0);
    result->next = next;
    // push(result, next);
  }
  return result;
}

ListNode *add_two(ListNode *l1, ListNode *l2) { return with_carry(l1, l2); }

void print_list(ListNode *head) {
  ListNode *walk = head;
  while (walk != NULL) {
    printf("%d -> ", walk->val);
    walk = walk->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  /* First linked list */
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  /* Second linked list */
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  ListNode *head = add_two(l1, l2);
  print_list(head);

  return 0;
}
