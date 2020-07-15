/* This program solves the equal subset sum problem given at:
 * https://leetcode.com/problems/partition-equal-subset-sum/ */

#include <bits/stdc++.h>
using namespace std;

bool can_partition(vector<int> &nums) {
  int sum = 0;
  for (int n : nums)
    sum += n;

  if (sum % 2 == 1)
    return false;

  sum /= 2;

  // row = nums, col = sum
  vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));

  for (int i = 0; i <= nums.size(); i++) {
    for (int j = 0; j <= sum; j++) {
      if (i == 0 && j == 0)
        dp[i][j] = true;
      else if (i == 0)
        dp[i][j] = false;
      else if (j == 0)
        dp[i][j] = true;
      else if (nums[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
    }
  }
  return dp[nums.size()][sum];
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 5, 11, 5};
  if (can_partition(nums))
    printf("True\n");
  else
    printf("False\n");
  return 0;
}
