/* This program implements quick select algorithm that is used to select k
min/max elements in unsorted array. */

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int l, int r) {
  int pivot = nums[r], w = l;
  for (int i = l; i <= r - 1; i++) {
    if (nums[i] <= pivot)
      swap(nums[w++], nums[i]);
  }
  swap(nums[w], nums[r]);
  return w;
}

int kth_smallest(vector<int> &nums, int l, int r, int k) {
  if (k > 0 && k <= (r - l + 1)) {
    int pindex = partition(nums, l, r);

    if (pindex - l == k - 1)
      return nums[pindex];

    if (pindex - l > k - 1)
      return kth_smallest(nums, l, pindex - 1, k);

    return kth_smallest(nums, pindex + 1, r, k - pindex + l - 1);
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {3, 3, 3, 2, 1, 1};
  int k = 1;
  printf("%d smallest num is %d\n", k,
         kth_smallest(nums, 0, nums.size() - 1, k));
  return 0;
}
