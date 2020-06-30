/* This program print tree traversal preorder */
#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Without recursion */
void preorder(TreeNode *A) {
  std::stack<TreeNode *> track;
  track.push(A);

  while (!track.empty()) {
    auto node = track.top();
    track.pop();

    while (node != NULL) {
      std::cout << node->val << std::endl;
      track.push(node->right);
      node = node->left;
    }
  }
}

int main(int argc, char const *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  preorder(root);
  return 0;
}
