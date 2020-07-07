/* You are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once. Find
this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int single_non_duplicate(vector<int> &nums) {
  int start = 0, end = nums.size() - 1, mid = (end + start) / 2;

  while (start < end) {
    mid = (end + start) / 2;

    if (mid % 2 == 0 && nums[mid] != nums[mid + 1])
      end = mid - 1;
    else if (mid % 2 == 0 && nums[mid] == nums[mid + 1])
      start = mid + 2;
    else if (mid % 2 == 1 && nums[mid] == nums[mid + 1])
      end = mid - 1;
    else
      start = mid + 1;
  }
  return nums[start];
}

int main(int argc, char const *argv[]) {
  // vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  // vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 8, 8};
  // vector<int> nums = {1, 1, 2};
  // vector<int> nums = {1, 2, 2};
  vector<int> nums = {1};
  int dup = single_non_duplicate(nums);
  printf("Non-Duplicate number is %d\n", dup);
  return 0;
}
