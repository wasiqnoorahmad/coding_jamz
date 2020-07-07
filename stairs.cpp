/* This program implements stairs program. Problem can be found at:
 * https://www.interviewbit.com/problems/stairs/ */
#include <bits/stdc++.h>
using namespace std;

int stairs(int n) {
  if (n < 3)
    return n;

  int memo[n + 1];
  memo[1] = 1, memo[2] = 2;

  for (int i = 3; i <= n; i++) {
    memo[i] = 0;
    for (int s = 1; s <= 2; s++) {
      memo[i] += memo[i - s];
    }
  }
  return memo[n];
}

int main(int argc, char const *argv[]) {
  int n = 6, steps = stairs(n);
  printf("Unique steps to reach %d are %d\n", n, steps);
  return 0;
}
