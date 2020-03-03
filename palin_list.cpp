#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Node {
  char data;
  struct Node* next;
};

bool compareLists(struct Node* head1, struct Node* head2) {
  struct Node* temp1 = head1;
  struct Node* temp2 = head2;

  while (temp1 && temp2) {
    if (temp1->data == temp2->data) {
      temp1 = temp1->next;
      temp2 = temp2->next;
    } else
      return 0;
  }

  if (temp1 == NULL && temp2 == NULL) return 1;

  return 0;
}

void push(struct Node** head_ref, char new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  new_node->data = new_data;

  new_node->next = (*head_ref);

  (*head_ref) = new_node;
}

Node* reverse(struct Node* head) {
  struct Node* prev = head;
  struct Node* curr = head->next;
  struct Node* next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

bool isPalindrome(struct Node* head) {
  // Pseudo Code
  // Find Mid ...
  // Reverse list second half ...
  // Compare ...

  struct Node* slow_ptr = head;
  struct Node* fast_ptr = head;
  struct Node* mid_ptr = head;
  struct Node* rsvd_ptr = NULL;

  if (head != NULL && head->next != NULL) {
    // Find the mid node...
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
      fast_ptr = fast_ptr->next->next;
      mid_ptr = slow_ptr;
      slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL) {
      rsvd_ptr = mid_ptr;
      mid_ptr = mid_ptr->next;
    }

    struct Node* tail = reverse(mid_ptr);

    // std::cout << "Tail ptr: " << tail->data << std::endl;
    // std::cout << "Mid ptr: " << mid_ptr->data << std::endl;

    if (head->next == tail && tail->next == head) {
      if (head->data == tail->data) {
        return true;
      }
      return false;
    }

    // Compare head and tail incrementally
    while (head != tail) {
      if (head->data != tail->data) {
        return false;
      }
      if (head->next == tail) {
        break;
      }
      head = head->next;
      tail = tail->next;
    }
  }
  return true;
}

void printList(struct Node* ptr) {
  while (ptr != NULL) {
    printf("%c->", ptr->data);
    ptr = ptr->next;
  }
  printf("NULL\n");
}

int main() {
  struct Node* head = NULL;
  char str[] = "8648";
  int i;

  for (i = 0; str[i] != '\0'; i++) {
    push(&head, str[i]);
  }

  printList(head);

  if (isPalindrome(head)) {
    printf("Is Palindrome\n");
  } else {
    printf("Not Palindrome\n");
  }

  return 0;
}
