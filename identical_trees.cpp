/* This program tells if you binary trees are identical
 * For two trees to be identical, they must have the same
 * data in same order.
 */

#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Using recursion */
bool is_identical(TreeNode *t1, TreeNode *t2) {
  if (t1 == t2)
    return true;
  if (t1 == NULL || t2 == NULL || t1->val != t2->val) {
    return false;
  }

  // Value is good.. now call for child
  return is_identical(t1->left, t2->left) && is_identical(t1->right, t2->right);
}

/* Without recursion */
bool is_identical2(TreeNode *t1, TreeNode *t2) {
  /* Using a walk pointer may be */
  if (t1 == t2)
    return true;

  std::stack<TreeNode *> track;
  track.push(t1);
  track.push(t2);

  while (!track.empty()) {
    auto root2 = track.top();
    track.pop();
    auto root1 = track.top();
    track.pop();

    if (root1 == root2)
      continue;

    if (root1 == NULL || root2 == NULL || root1->val != root2->val)
      return false;

    track.push(root1->left);
    track.push(root2->left);

    track.push(root1->right);
    track.push(root2->right);
  }
  return true;
}

int main(int argc, char const *argv[]) {
  /* Making first tree -- t1 */
  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  t1->right = new TreeNode(3);
  t1->left->left = new TreeNode(4);
  t1->left->right = new TreeNode(5);

  /* Makign another tree -- t2 */
  TreeNode *t2 = new TreeNode(1);
  t2->left = new TreeNode(2);
  t2->right = new TreeNode(3);
  t2->left->left = new TreeNode(4);
  t2->left->right = new TreeNode(1);

  std::cout << is_identical2(t1, t2) << std::endl;
  return 0;
}
