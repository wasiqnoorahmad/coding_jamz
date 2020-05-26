/* This program calculates the maximum sum subarray of +ve as well as -ve
 * numbers */
#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int>& nums) {
  int curr_sum = nums[0], max_so_far = curr_sum;

  for (int i = 1; i < nums.size(); i++) {
    curr_sum = max(nums[i], curr_sum + nums[i]);
    max_so_far = max(max_so_far, curr_sum);
  }
  return max_so_far;
}

int main(int argc, char const* argv[]) {
  vector<int> nums = {-1, -2, -3};
  printf("Max sum is %d\n", max_sum(nums));
  return 0;
}
