/* This program implements Dungeon problem available at:
 * https://leetcode.com/problems/dungeon-game/ */
#include <bits/stdc++.h>
using namespace std;

int min_initial_points(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size(), dp[m][n];

  dp[m - 1][n - 1] = grid[m - 1][n - 1] > 0 ? 1 : abs(grid[m - 1][n - 1]) + 1;

  // Fill last row and last column as base to fill
  // entire table
  for (int i = m - 2; i >= 0; i--)
    dp[i][n - 1] = max(dp[i + 1][n - 1] - grid[i][n - 1], 1);
  for (int j = n - 2; j >= 0; j--)
    dp[m - 1][j] = max(dp[m - 1][j + 1] - grid[m - 1][j], 1);

  for (int i = m - 2; i >= 0; i--)
    for (int j = n - 2; j >= 0; j--)
      dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j], 1);

  return dp[0][0];
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> points = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
  printf("%d\n", min_initial_points(points));
  return 0;
}
