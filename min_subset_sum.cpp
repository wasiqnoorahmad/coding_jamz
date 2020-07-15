/* This program solves the minimum subset sum difference. */
#include <bits/stdc++.h>
using namespace std;

int min_subset_diff(vector<int> &nums) {
  int sum = 0;
  for (int n : nums)
    sum += n;

  int n = nums.size();
  vector<vector<bool>> dp(n, vector<bool>((sum / 2) + 1, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= sum / 2; j++) {
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

  int sum1 = 0;
  for (int i = sum / 2; i >= 0; i--) {
    if (dp[n - 1][i] == true) {
      sum1 = i;
      break;
    }
  }
  int sum2 = sum - sum1;
  return abs(sum2 - sum1);
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 2, 3, 9};
  printf("Min Subset Difference %d\n", min_subset_diff(nums));
  return 0;
}
