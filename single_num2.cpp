/* Given an unsorted array of numbers, every number appears thrice except one.
  Find that number.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
  int unique = 0;

  for (int i = 0; i < 32; i++) {
    int tmp = 0;
    for (int j = 0; j < nums.size(); j++) {
      tmp += (nums[j] & 1);
      nums[j] >>= 1;
    }
    tmp = tmp % 3;
    unique += (tmp << i);
  }
  return unique;
}

/* Using XOR */
int solve2(vector<int> &nums) {
  int ones = 0, twos = 0;

  for (int n : nums) {
    ones = (ones ^ n) & ~twos;
    twos = (twos ^ n) & ~ones;
  }

  return ones;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
  printf("Only occuring number is %d\n", solve2(nums));
  return 0;
}
