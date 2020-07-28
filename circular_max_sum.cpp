/* This program calculates the maximum sum in a circular sub-array */

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &nums) {
  int curr_sum = nums[0], max_so_far = curr_sum;

  for (int i = 1; i < nums.size(); i++) {
    curr_sum = max(nums[i], curr_sum + nums[i]);
    max_so_far = max(max_so_far, curr_sum);
  }
  return max_so_far;
}

int circular_max_sum(vector<int> &nums) {
  int max_sum = kadane(nums), total = 0;
  if(max_sum < 0)
    return max_sum;

  for (int i = 0; i < nums.size(); i++) {
    total += nums[i];
    nums[i] *= -1;
  }

  return max(total + kadane(nums), max_sum);
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {5, -3, 5};
  printf("Max sum is %d\n", circular_max_sum(nums));
  return 0;
}
