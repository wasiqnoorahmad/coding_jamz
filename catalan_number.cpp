/*
  This program implements catalan series using dynamic programming.
  Catalan number is defined as:
    T(n) = Sum[i=0->n-1] T(i) * T(n-i-1)
*/

#include <bits/stdc++.h>
using namespace std;

int nth_catalan(int n) {
  int dp[n + 1];
  dp[0] = dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = 0;
    for (int j = 0; j < i; j++) {
      dp[i] += (dp[j] * dp[i - j - 1]);
    }
  }
  return dp[n];
}

int main(int argc, char const *argv[]) {
  int n = 0;
  printf("Catalan(%d) = %d\n", n, nth_catalan(n));
  return 0;
}
