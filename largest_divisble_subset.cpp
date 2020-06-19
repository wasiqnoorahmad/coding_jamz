/* Given a set of distinct positive integers, find the largest subset such that
every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

 */
#include <bits/stdc++.h>

#include "common.hpp"
using namespace std;

vector<int> largest_divisible_subset(vector<int>& nums) {
  int n = nums.size();
  if (n <= 1) return nums;
  sort(nums.begin(), nums.end());

  // vector<int> sizes(n, 1);
  vector<int> sizes(n, 1);
  vector<int> next_index(n, -1);
  int max_len = 1, max_indx = 0;

  for (int i = n - 1; i >= 0; i--) {
    int j = i + 1, _max = 0, _indx = i;
    while (j < n) {
      if (nums[j] % nums[i] == 0 && sizes[j] > _max) {
        _max = sizes[j], _indx = j;
      }
      j++;
    }

    if (_indx != i) {
      sizes[i] += sizes[_indx];
      next_index[i] = _indx;
      if (_max + 1 > max_len) {
        max_len = _max + 1, max_indx = i;
      }
    }
  }

  vector<int> result;
  int curr = max_indx;
  while (curr >= 0) {
    result.push_back(nums[curr]);
    curr = next_index[curr];
  }
  return result;
}

int main(int argc, char const* argv[]) {
  vector<int> nums = {1, 2, 3};
  vector<int> ans = largest_divisible_subset(nums);
  p_vector(ans);
  return 0;
}
