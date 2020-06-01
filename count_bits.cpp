/* Given a non negative integer number num. For every numbers i in the range 0 ≤
i ≤ num calculate the number of 1's in their binary representation and return
them as an array.

Example 1:

Input: 2
Output: [0,1,1]

Example 2:

Input: 5
Output: [0,1,1,2,1,2]
 */

#include <bits/stdc++.h>

#include "common.hpp"
using namespace std;

vector<int> count_bits(int num) {
  vector<int> result(num + 1);
  result[0] = 0;

  for (int i = 1; i <= num; i++) {
    result[i] = result[i >> 1] + (i & 1);
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int num = 10;
  vector<int> result = count_bits(num);
  p_vector(result);
  return 0;
}
