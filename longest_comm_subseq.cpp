/* This program implements longest common sub-sequence program. Problem can be
 * found at: <link> */

#include <bits/stdc++.h>
using namespace std;

int long_sub_seq(string src, string dst) {
  int dp[dst.length() + 1][src.length() + 1];

  for (int i = 0; i <= dst.length(); i++) {
    for (int j = 0; j <= src.length(); j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (dst[i - 1] == src[j - 1])
        dp[i][j] = (1 + dp[i - 1][j - 1]);
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[dst.length()][src.length()];
}

int main(int argc, char const *argv[]) {
  // string src = "GXTXAYB";
  // string dst = "AGGTAB";

  // string src = "ABCDGH";
  // string dst = "AEDFHR";

  string src = "BACDB";
  string dst = "BDCB";
  int len = long_sub_seq(src, dst);
  cout << "Length is " << len << endl;
  return 0;
}
