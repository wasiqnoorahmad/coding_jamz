/* This code implements fibonacci using dynamic programming */
#include <bits/stdc++.h>
using namespace std;

int fab(int n) {
  /* Safety Check */
  if (n < 0)
    return -1;

  /* Base Case */
  if (n == 1 || n == 2)
    return n - 1;

  /* Last and Second Last */
  int last = 1, second_last = 0, f;
  for (int i = 3; i <= n; i++) {
    f = last + second_last;

    second_last = last;
    last = f;
  }
  return f;
}

int main(int argc, char const *argv[]) {
  for (int i = 1; i < 15; i++) {
    printf("N = %d --> Fab = %d\n", i, fab(i));
  }
  return 0;
}
