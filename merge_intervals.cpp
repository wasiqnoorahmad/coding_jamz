/* This program solve the problem of merge intervals available at:
 * https://leetcode.com/problems/merge-intervals/submissions/ */
#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<vector<int>> result;
  sort(intervals.begin(), intervals.end());

  result.push_back(intervals[0]);
  int walk = 1;
  while (walk < intervals.size()) {
    if (result.back()[1] >= intervals[walk][0]) {
      result.back()[1] = max(result.back()[1], intervals[walk][1]);
    } else {
      result.push_back(intervals[walk]);
    }
    walk++;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
  vector<vector<int>> result = merge(intervals);
  for (auto v : result)
    p_vector(v);
  return 0;
}
