/* This program removes duplicates from a sorted array. Statement can be found
 * at:
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
 */

#include <bits/stdc++.h>

#include "common.hpp"
using namespace std;

int rmv_duplicates(vector<int> &nums) {
  int left = 0, right = 1;

  while (left < nums.size()) {
    right = left + 1;
    while (right < nums.size() && nums[left] == nums[right])
      right++;
    nums.erase(nums.begin() + left + 1, nums.begin() + right);
    left++;
  }
  return nums.size();
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {0};
  p_vector(nums);
  int size = rmv_duplicates(nums);
  printf("New size is %d\n", size);
  p_vector(nums);
  return 0;
}
