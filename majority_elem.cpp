/* This program implements Boyer-Moore algorithm to find the majority
  element in an unsorted array.
  Problem can be found at: https://leetcode.com/problems/majority-element/
*/
#include <bits/stdc++.h>
using namespace std;

int boyer_moore(vector<int> &nums) {
  int count = 0, majority;
  for (int i = 0; i < nums.size(); i++) {
    if (count == 0)
      majority = nums[i];

    if (nums[i] == majority)
      count++;
    else
      count--;
  }
  return majority;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  printf("Majority element is %d\n", boyer_moore(nums));
  return 0;
}
