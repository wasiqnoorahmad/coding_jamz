/* This program implements Morris Inorder Traversal that does not
    uses recursion or stack.
*/

#include <stdio.h>
#include <stdlib.h>

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode {
  int data;
  struct tNode *left;
  struct tNode *right;
};

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode *newtNode(int data) {
  struct tNode *node = new tNode;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

struct tNode *find_predessor(struct tNode *head) {
  struct tNode *walk = head->left;
  // Go to extreme right as possible
  while (walk->right && walk->right != head) {
    walk = walk->right;
  }
  return walk;
}

/* Function to traverse the binary tree without recursion and
without stack */
void morris_traversal(struct tNode *root) {
  struct tNode *curr = root;

  while (curr) {
    if (curr->left == NULL) {
      printf("%d->", curr->data);
      curr = curr->right;
    } else {
      struct tNode *predessor = find_predessor(curr);
      if (predessor->right == NULL) {
        predessor->right = curr;
        curr = curr->left;
      } else {
        predessor->right = NULL;
        printf("%d->", curr->data);
        curr = curr->right;
      }
    }
  }
  printf("\n");
}

/* Driver program to test above functions*/
int main() {

  /* Constructed binary tree is
           1
          / \
         2	 3
        / \
       4	 5
  */
  struct tNode *root = newtNode(1);
  root->left = newtNode(2);
  root->right = newtNode(3);
  root->left->left = newtNode(4);
  root->left->right = newtNode(5);

  morris_traversal(root);

  return 0;
}
