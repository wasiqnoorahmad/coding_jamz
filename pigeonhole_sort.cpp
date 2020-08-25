/* This program implements pigeonhole sorting algorithm */
#include <bits/stdc++.h>
using namespace std;

vector<int> pigeonhole_sort(const vector<int> &nums) {
  int n = nums.size(), gmin = INT_MAX, gmax = INT_MIN;

  for (int x : nums) {
    gmin = min(gmin, x);
    gmax = max(gmax, x);
  }
  int range = gmax - gmin + 1;
  vector<vector<int>> holes(range);
  for (int x : nums) {
    holes[x - gmin].push_back(x);
  }

  vector<int> result;
  for (int i = 0; i < range; i++) {
    for (auto x : holes[i]) {
      result.push_back(x);
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {8, 3, 2, 7, 4, 6, 8};
  vector<int> result = pigeonhole_sort(nums);
  for (int n : result)
    cout << n << " ";
  cout << endl;
  return 0;
}
