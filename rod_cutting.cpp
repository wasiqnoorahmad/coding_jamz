/* This program the famous rod cutting problem using DP */
#include <bits/stdc++.h>
using namespace std;

int rod_cutting(vector<int> &profits) {
  vector<int> dp(profits.size() + 1, 0);
  int n = profits.size();

  for (int i = 1; i <= n; i++) {
    int max_profit = INT_MIN;
    for (int j = 0; j < i; j++) {
      max_profit = max(max_profit, profits[j] + dp[i - j - 1]);
    }
    dp[i] = max_profit;
  }
  return dp[n];
}

int main(int argc, char const *argv[]) {
  vector<int> profits = {1, 5, 8, 9, 10, 17, 17, 20};
  printf("Max Profit is %d\n", rod_cutting(profits));
  return 0;
}
