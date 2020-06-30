/* Problem can be found at
 * https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
 */
#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &nums, int l, int h, int v) {

  while (l <= h) {
    int mid = (l + h) / 2;

    if (nums[mid] == v)
      return mid;
    else if (nums[mid] > v)
      h = mid - 1;
    else
      l = mid + 1;
  }

  return -1;
}

int find_position(vector<int> &nums, int key) {
  int l = 0, h = 1, val = nums[0];

  while (val < key) {
    l = h;
    h *= 2;
    val = nums[h];
  }
  return h;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
  int h = find_position(nums, 10);
  int i = binary_search(nums, 0, h, 10);
  if (i == -1)
    printf("Element not found\n");
  else
    printf("Element found at index %d\n", i);
  return 0;
}
