/* This program checks if a set can be partitioned into two subsets such that
 * the sum of two subsets remain same. Pronlem can be found at:
 * https://practice.geeksforgeeks.org/problems/subset-sum-problem/0 */

#include <bits/stdc++.h>
using namespace std;

bool partition(vector<int> &nums) {
  int total = accumulate(nums.begin(), nums.end(), 0);
  /* If sum is odd, subsets can never have same sum */
  if (total % 2 == 1) return false;

  total /= 2;

  bool dp[nums.size() + 1][total + 1];

  /* If there is zero item, no sum can be achieved */
  for (int t = 0; t <= total; t++) dp[0][t] = false;
  /* If total sum is zero, it can be always achieved with empty set */
  for (int i = 0; i <= nums.size(); i++) dp[i][0] = true;

  /* Build up till all sums */
  for (int i = 1; i <= nums.size(); i++) {
    for (int t = 1; t <= total; t++) {
      dp[i][t] = dp[i - 1][t];
      if (t >= nums[i - 1])
        dp[i][t] = dp[i - 1][t] || dp[i - 1][t - nums[i - 1]];
    }
  }

  return dp[nums.size()][total];
}

int main(int argc, char const *argv[]) {
  // vector<int> nums = {478, 757, 314, 471, 729, 100, 459, 618};
  // vector<int> nums = {1, 5, 11, 5};
  vector<int> nums = {3, 1, 1, 2, 2, 1};

  if (partition(nums))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
