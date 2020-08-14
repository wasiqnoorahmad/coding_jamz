/* This program solves the problem given at:
 * https://www.interviewbit.com/problems/first-missing-integer/ */
#include <bits/stdc++.h>
using namespace std;

int first_missing_positive(vector<int> &nums) {
  // Bring -ve nums at start ...
  int w = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0) {
      swap(nums[i], nums[w]);
      w++;
    }
  }

  for (int i = w; i < nums.size(); i++) {
    if (abs(nums[i]) + w - 1 < nums.size() && nums[abs(nums[i]) + w - 1] >= 0)
      nums[abs(nums[i]) + w - 1] = -nums[abs(nums[i]) + w - 1];
  }

  for (int i = 0; i < nums.size(); i++)
    if (nums[i] > 0)
      return i - w + 1;
  return nums.size() - w + 1;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {3, 4, -1, 1};
  printf("First missing number is %d\n", first_missing_positive(nums));
  return 0;
}
