/* This program prints tree in level order */
#include <bits/stdc++.h>

#include "common.hpp"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef std::vector<std::vector<int>> dvector_t;

/* Without recursion */
dvector_t level_order(TreeNode* A) {
  dvector_t result;
  std::queue<TreeNode*> track;
  track.push(A);
  track.push(NULL);

  while (!track.empty()) {
    std::vector<int> lvl;

    while (track.front() != NULL) {
      auto curr = track.front();
      track.pop();
      lvl.push_back(curr->val);

      if (curr->left) track.push(curr->left);
      if (curr->right) track.push(curr->right);
    }
    track.pop();
    if (!track.empty()) track.push(NULL);
    result.push_back(lvl);
  }
  return result;
}

int main(int argc, char const* argv[]) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->left->left = new TreeNode(7);
  root->left->left->left->right = new TreeNode(9);
  root->right->right = new TreeNode(6);
  root->right->right->right = new TreeNode(8);

  dvector_t result = level_order(root);

  for (std::vector<int>& lvl : result) {
    p_vector(lvl);
  }
  return 0;
}
