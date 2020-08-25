/* This program implements maximum consecutive gap problem given at :
 * https://www.interviewbit.com/problems/maximum-consecutive-gap/ */
#include <bits/stdc++.h>
using namespace std;

int max_adj_diff(const vector<int> &nums) {
  int n = nums.size();

  if (n < 2)
    return 0;

  int gmin = nums[0], gmax = nums[0];
  for (int i = 1; i < n; i++) {
    gmin = min(gmin, nums[i]);
    gmax = max(gmax, nums[i]);
  }
  vector<pair<int, int>> holes(n - 1, make_pair(INT_MAX, INT_MIN));
  float delta = (float)(gmax - gmin) / (float)(n - 1);

  for (int i = 0; i < n; i++) {
    if (nums[i] == gmin || nums[i] == gmax)
      continue;
    int index = (float)(floor(nums[i] - gmin) / delta);

    if (holes[index].first == INT_MAX)
      holes[index].first = nums[i];
    else
      holes[index].first = min(holes[index].first, nums[i]);

    if (holes[index].second == INT_MIN)
      holes[index].second = nums[i];
    else
      holes[index].second = max(holes[index].second, nums[i]);
  }

  int prev = gmin, gap = 0;

  for (int i = 0; i < n - 1; i++) {
    if (holes[i].first == INT_MAX)
      continue;

    gap = max(gap, holes[i].first - prev);
    prev = holes[i].second;
  }

  gap = max(gap, gmax - prev);
  return gap;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 10, 5};
  cout << max_adj_diff(nums) << endl;
  return 0;
}
