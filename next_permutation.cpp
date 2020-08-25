/* This program finds the next permuation of sequence of numbers */
#include <bits/stdc++.h>
using namespace std;

vector<int> nxt_permutation(vector<int> nums) {
  int len = nums.size(), i = len - 1, j = len - 1;

  while (i > 0 && nums[i - 1] >= nums[i])
    i--;

  // cout << "i = " << i << endl;
  if (i == 0) {
    reverse(nums.begin(), nums.end());
    return nums;
  }

  while (nums[j] <= nums[i - 1])
    j--;

  swap(nums[i - 1], nums[j]);

  reverse(nums.begin() + i, nums.end());
  return nums;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {769, 533};
  vector<int> nxt = nxt_permutation(nums);

  cout << "Next Permutation is: ";
  for (auto x : nxt)
    cout << x << " ";
  cout << endl;
  return 0;
}
