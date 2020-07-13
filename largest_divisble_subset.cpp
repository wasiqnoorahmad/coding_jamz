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

vector<int> largest_divisible_subset(vector<int> &nums) {
  int n = nums.size();
  if (n <= 1)
    return nums;

  sort(nums.begin(), nums.end());
  /* div_count[i] stores the size of divisible subset ending at arr[i] */
  vector<int> div_count(n, 1);
  vector<int> prev(n, -1);

  int max_indx = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {

      if (nums[i] % nums[j] == 0 && div_count[i] < div_count[j] + 1) {
        div_count[i] = div_count[j] + 1;
        prev[i] = j;
      }
    }

    if (div_count[max_indx] < div_count[i])
      max_indx = i;
  }

  vector<int> result;

  int k = max_indx;
  while (k >= 0) {
    result.push_back(nums[k]);
    k = prev[k];
  }

  return result;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 2, 17, 4};
  vector<int> ans = largest_divisible_subset(nums);
  p_vector(ans);
  return 0;
}
