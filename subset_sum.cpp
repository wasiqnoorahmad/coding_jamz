/* This program checks if there exists a subset of sum k */
#include <bits/stdc++.h>
using namespace std;

bool is_subset_sum(vector<int> &nums, int target) {
  vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
  for (int i = 0; i <= nums.size(); i++) {
    for (int j = 0; j <= target; j++) {
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
  return dp[nums.size()][target];
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 5, 11, 5};
  if (is_subset_sum(nums, 6))
    printf("True\n");
  else
    printf("False\n");
  return 0;
}
