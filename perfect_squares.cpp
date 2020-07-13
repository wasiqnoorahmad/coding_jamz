/* This program solves the perfect squares problem available at:
  https://leetcode.com/problems/perfect-squares/
 */

#include <bits/stdc++.h>
using namespace std;

int perfect_squares(int n) {
  int r = (int)(sqrt(n)), c = n, dp[r + 1][c + 1];

  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= c; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (i == 1)
        dp[i][j] = j;
      else if (j < i * i)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = min(dp[i - 1][j], dp[i][j - (i * i)] + 1);
    }
  }
  return dp[r][c];
}

int main(int argc, char const *argv[]) {
  int n = 12;
  printf("Minimum number of perfect squares are %d\n", perfect_squares(n));
  return 0;
}
