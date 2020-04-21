/* This program computes k sequence from three prime numbers */
#include <bits/stdc++.h>

#include "common.hpp"

std::vector<int> k_sequence(int A, int B, int C, int D) {
  std::set<int> nums;
  nums.insert(A);
  nums.insert(B);
  nums.insert(C);

  std::vector<int> result;
  int count = 0, curr;

  while (count < D) {
    curr = *(nums.begin());
    nums.erase(curr);
    result.push_back(curr);

    nums.insert(curr * A);
    nums.insert(curr * B);
    nums.insert(curr * C);
    count++;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  std::vector<int> result = k_sequence(5, 7, 11, 7);
  p_vector(result);
  return 0;
}
