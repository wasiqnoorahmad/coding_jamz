/* This program implements 0/1 knapsack problem */
#include <bits/stdc++.h>
using namespace std;

int knapsack(const vector<int> &profits, const vector<int> &weights,
             int capacity) {
  vector<vector<int>> dp(weights.size() + 1, vector<int>(capacity + 1));

  for (int i = 0; i <= weights.size(); i++) {
    for (int j = 0; j <= capacity; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (weights[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] =
            max(dp[i - 1][j], profits[i - 1] + dp[i - 1][j - weights[i - 1]]);
    }
  }
  return dp[weights.size()][capacity];
}

int main(int argc, char const *argv[]) {
  vector<int> profits = {60, 100, 120}, weights = {10, 20, 30};
  int capacity = 50;
  printf("Max profit = %d\n", knapsack(profits, weights, capacity));
  return 0;
}
