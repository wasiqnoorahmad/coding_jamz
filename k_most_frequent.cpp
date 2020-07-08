/* This program implements K most frequest element algorithm using partition
 * algorithm */
#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, unordered_map<int, int> &freq, int l, int r) {
  int pivot_freq = freq[nums[r]], w = l;

  for (int i = l; i <= r - 1; i++) {
    if (freq[nums[i]] <= pivot_freq)
      swap(nums[w++], nums[i]);
  }
  swap(nums[w], nums[r]);
  return w;
}

void quick_select(vector<int> &nums, unordered_map<int, int> &freq, int l,
                  int r, int k) {

  if (l == r)
    return;

  int pindex = partition(nums, freq, l, r);

  if (pindex == k)
    return;
  else if (pindex > k)
    quick_select(nums, freq, l, pindex - 1, k);
  else
    quick_select(nums, freq, pindex + 1, r, k);
}

vector<int> k_most_freq(vector<int> &nums, int k) {
  vector<int> freq;
  unordered_map<int, int> um;
  for (int n : nums)
    um[n]++;

  vector<int> unique;
  for (auto it = um.begin(); it != um.end(); it++) {
    unique.push_back(it->first);
  }

  // Quick Select ...
  int n = um.size();
  quick_select(unique, um, 0, n - 1, n - k);

  for (int i = n - k; i < n; i++)
    freq.push_back(unique[i]);
  return freq;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {3, 1, 4, 4, 5, 2, 2, 6, 1};
  vector<int> freq = k_most_freq(nums, 3);
  p_vector(freq);
  return 0;
}
