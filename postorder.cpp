/* This program print tree traversal postorder */
#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Without recursion using two stacks */
void postorder2(TreeNode* A) {
  std::stack<TreeNode*> s1;
  std::stack<TreeNode*> s2;

  s1.push(A);

  while (!s1.empty()) {
    auto node = s1.top();
    s1.pop();
    s2.push(node);

    if (node->left) s1.push(node->left);
    if (node->right) s1.push(node->right);
  }

  // Print s2 ..
  while (!s2.empty()) {
    auto node = s2.top();
    s2.pop();
    std::cout << node->val << std::endl;
  }
}

/* Without recursion using one stacks */
void postorder(TreeNode* A) {
  std::stack<TreeNode*> track;
  TreeNode* curr = A;

  while (curr != NULL || !track.empty()) {
    while (curr != NULL) {
      if (curr->right) track.push(curr->right);
      track.push(curr);
      curr = curr->left;
    }

    curr = track.top();
    track.pop();

    if (curr->right && !track.empty() && curr->right == track.top()) {
      track.pop();
      track.push(curr);
      curr = curr->right;
    } else {
      std::cout << curr->val << std::endl;
      curr = NULL;
    }
  }
}

int main(int argc, char const* argv[]) {
  // TreeNode* root = new TreeNode(1);
  // root->left = new TreeNode(12);
  // root->right = new TreeNode(9);
  // root->left->left = new TreeNode(5);
  // root->left->right = new TreeNode(6);

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->left->left = new TreeNode(7);
  root->left->left->left->right = new TreeNode(9);
  root->right->right = new TreeNode(6);
  root->right->right->right = new TreeNode(8);

  // postorder2(root);
  postorder(root);
  return 0;
}
