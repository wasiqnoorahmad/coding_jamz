/* This program calculates the maximum sum subarray of +ve as well as -ve
 * numbers */
#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &nums) {
  int curr_sum = nums[0], max_so_far = curr_sum;

  for (int i = 1; i < nums.size(); i++) {
    curr_sum = max(nums[i], curr_sum + nums[i]);
    max_so_far = max(max_so_far, curr_sum);
  }
  return max_so_far;
}

int max_cross_sum(vector<int> &nums, int low, int mid, int high) {
  int sum = 0, right_sum = INT_MIN, left_sum = INT_MIN;

  for (int i = mid; i >= low; i--) {
    sum += nums[i];
    left_sum = max(left_sum, sum);
  }

  sum = 0;
  for (int i = mid + 1; i <= high; i++) {
    sum += nums[i];
    right_sum = max(right_sum, sum);
  }

  return max({left_sum + right_sum, right_sum, left_sum});
}

int max_sum_recur(vector<int> &nums, int low, int high) {
  if (high == low)
    return nums[low];
  int mid = (low + high) / 2;
  return max({max_sum_recur(nums, low, mid), max_sum_recur(nums, mid + 1, high),
              max_cross_sum(nums, low, mid, high)});
}

int max_sum_recur(vector<int> &nums) {
  return max_sum_recur(nums, 0, nums.size() - 1);
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {-2, -5, 6, -2, -3, 1, 5, -6};
  printf("Max sum is %d\n", max_sum_recur(nums));
  return 0;
}
