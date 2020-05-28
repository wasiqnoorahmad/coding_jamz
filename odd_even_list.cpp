/* Given a singly linked list, group all odd nodes together followed by the even
nodes. Please note here we are talking about the node number and not the value
in the nodes.

You should try to do it in place. The program should run in O(1) space
complexity and O(nodes) time complexity.

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
*/

#include <bits/stdc++.h>

#include "common.hpp"
using namespace std;

ListNode* odd_even_list(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;

  ListNode *odd = head, *even = head->next, *even_head = even, *odd_tail = NULL;

  while (odd != NULL && even != NULL) {
    odd->next = even->next, odd_tail = odd, odd = odd->next;
    if (odd) even->next = odd->next, even = even->next;
  }

  if (odd) odd_tail = odd_tail->next;
  odd_tail->next = even_head;

  return head;
}

int main(int argc, char const* argv[]) {
  ListNode* head = new ListNode(2);
  insert_node(head, 1);
  insert_node(head, 3);
  insert_node(head, 5);
  insert_node(head, 6);
  insert_node(head, 4);
  insert_node(head, 7);
  // insert_node(head, 8);
  // insert_node(head, 9);

  ListNode* ans = odd_even_list(head);
  p_list(ans);
  return 0;
}
