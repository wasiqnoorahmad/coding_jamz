/* This program calculates the maximum rectangle under the histogram */
#include <bits/stdc++.h>
using namespace std;

int max_area(vector<int> &nums) {
  int max_area = -1, i = 0, area = 0, tp;
  stack<int> s;

  while (i < nums.size()) {
    if (s.empty() || nums[i] >= nums[s.top()]) {

      s.push(i++);
    } else {
      tp = s.top();
      s.pop();

      area = nums[tp] * (s.empty() ? i : i - s.top() - 1);
      max_area = max(max_area, area);
    }
  }

  while (!s.empty()) {
    tp = s.top();
    s.pop();

    area = nums[tp] * (s.empty() ? i : i - s.top() - 1);
    max_area = max(max_area, area);
  }

  return max_area;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {6, 2, 5, 4, 5, 1, 6};
  printf("Max rectangle area under histogram is %d\n", max_area(nums));
  return 0;
}
