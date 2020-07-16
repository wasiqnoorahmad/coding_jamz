/* This program solves the unbounded knapsack problem */
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &profits, vector<int> &weights, int capacity) {
  vector<int> dp(capacity + 1, 0);

  for (int i = 0; i <= capacity; i++) {
    for (int j = 0; j < weights.size(); j++) {
      if (weights[j] <= i)
        dp[i] = max(dp[i], profits[j] + dp[i - weights[j]]);
    }
  }
  return dp[capacity];
}

int main(int argc, char const *argv[]) {
  vector<int> profits = {10, 30, 20}, weights = {5, 10, 15};
  int capacity = 100;
  printf("Max profit = %d\n", knapsack(profits, weights, capacity));
  return 0;
}
