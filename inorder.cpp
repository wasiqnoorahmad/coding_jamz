/* This program print tree traversal inorder */
#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Without recursion */
void inorder(TreeNode *A) {
  std::stack<TreeNode *> track;
  TreeNode *curr = A;

  while (curr != NULL || !track.empty()) {
    while (curr != NULL) {
      track.push(curr);
      curr = curr->left;
    }

    curr = track.top();
    track.pop();

    std::cout << curr->val << std::endl;
    curr = curr->right;
  }
}

int main(int argc, char const *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  inorder(root);
  return 0;
}
