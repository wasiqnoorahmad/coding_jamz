/* This program implement coin change problem which can be found at:
 * https://practice.geeksforgeeks.org/problems/coin-change/0 */

#include <bits/stdc++.h>
using namespace std;

int count_change(int change, int coins[], int n) {
  int dp[n + 1][change + 1];

  for (int coin = 0; coin <= n; coin++) {
    for (int ch = 0; ch <= change; ch++) {
      if (coin == 0)
        dp[coin][ch] = 0;
      else if (ch == 0)
        dp[coin][ch] = 1;

      else if (ch < coins[coin - 1]) {
        dp[coin][ch] = dp[coin - 1][ch];
      } else {
        dp[coin][ch] = dp[coin - 1][ch] + dp[coin][ch - coins[coin - 1]];
      }
    }
  }
  return dp[n][change];
}

int main(int argc, char const *argv[]) {
  int coins[] = {2, 5, 3, 6};
  int change = 10;
  int size = sizeof(coins) / sizeof(coins[0]);
  printf("Possible ways to give change are %d\n",
         count_change(change, coins, size));
  // 5
  return 0;
}
