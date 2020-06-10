/* This program finds the maximum bit gap of zero's between two ones

Example 1:
Input:  10010001
Output: 3

Example 2:
Input:  11111
Output: 0

Example 3:
Input:  0110101001
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int bit_gap(int number) {
  if (number == 0 || (number & (number - 1)) == 0) return -1;

  int zeros = 0, max_gap = 0;
  while (number) {
    if (number & 1) {
      number >>= 1, zeros = 0;
      // Walk until next 1, and count zeros
      while (number && (number & 1) == 0) number >>= 1, zeros++;

    } else {
      number >>= 1;
    }

    max_gap = max(max_gap, zeros);
  }

  return max_gap;
}

int main(int argc, char const *argv[]) {
  // printf("%d\n", bit_gap(0b10010001));
  // printf("%d\n", bit_gap(0b1000));
  printf("%d\n", bit_gap(0b01010100010));
  return 0;
}
