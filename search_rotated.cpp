/* This program searches a number in a rotated array against unknown pivot.
 * Problem can be found at:
 * https://leetcode.com/problems/search-in-rotated-sorted-array/ */

#include <bits/stdc++.h>
using namespace std;

int find_pivot(vector<int> &nums, int start, int end) {
  if (end < start)
    return -1;
  if (end == start)
    return end;

  int mid = (end + start) / 2;
  if (mid < end && nums[mid] > nums[mid + 1])
    return mid;

  if (mid > start && nums[mid] < nums[mid - 1])
    return mid - 1;

  if (nums[mid] <= nums[start])
    return find_pivot(nums, start, mid - 1);

  return find_pivot(nums, mid + 1, end);
}

int binary_search(vector<int> &nums, int target, int start, int end) {
  if (end < start)
    return -1;

  int mid = (end + start) / 2;
  if (nums[mid] == target)
    return mid;
  if (nums[mid] < target)
    return binary_search(nums, target, mid + 1, end);
  return binary_search(nums, target, start, mid - 1);
}

int search(vector<int> &nums, int target) {
  int pivot = find_pivot(nums, 0, nums.size() - 1);
  printf("Pivot is %d\n", pivot);
  if (pivot == -1)
    return binary_search(nums, target, 0, nums.size() - 1);
  if (nums[pivot] == target)
    return pivot;

  if (nums[0] <= target)
    return binary_search(nums, target, 0, pivot - 1);
  return binary_search(nums, target, pivot + 1, nums.size() - 1);
}

int main(int argc, char const *argv[]) {
  // vector<int> src = {4, 5, 6, 7, 0, 1, 2};
  // printf("%d\n", search(src, 0));

  // vector<int> src = {7, 8, 1, 2, 3, 4, 5, 6};
  // printf("%d\n", search(src, 2));

  vector<int> src = {1, 3, 5};
  printf("%d\n", search(src, 3));

  return 0;
}
