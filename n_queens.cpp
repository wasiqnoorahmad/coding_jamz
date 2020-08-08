/* This program solves the famous placing n queen on n*n bpard */
#include <bits/stdc++.h>
using namespace std;

int queens = 0;

void solve(int r, int n, vector<bool> &col, vector<bool> &diag1,
           vector<bool> &diag2) {
  if (r == n) {
    queens++;
    return;
  } else {
    for (int i = 0; i < n; i++) {
      if (col[i] || diag1[i + r] || diag2[i - r + n - 1])
        continue;
      col[i] = diag1[i + r] = diag2[i - r + n - 1] = true;
      solve(r + 1, n, col, diag1, diag2);
      col[i] = diag1[i + r] = diag2[i - r + n - 1] = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  int n = 4;
  vector<bool> col(n, false), diag1(n, false), diag2(n, false);
  solve(0, n, col, diag1, diag2);
  printf("Number of ways to place %d queen are = %d\n", n, queens);
  return 0;
}
