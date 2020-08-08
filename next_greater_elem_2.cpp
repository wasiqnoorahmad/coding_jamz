/* This program solves the problem given
 * at:https://leetcode.com/problems/next-greater-element-ii/solution/ */
#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int> &nums) {
  vector<int> result(nums.size());
  stack<int> ss;

  for (int i = 2 * nums.size() - 1; i >= 0; i--) {
    while (!ss.empty() && nums[ss.top()] <= nums[i % nums.size()]) {
      ss.pop();
    }
    result[i % nums.size()] = ss.empty() ? -1 : nums[ss.top()];
    ss.push(i % nums.size());
  }
  return result;
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 2, 1};
  vector<int> result = next_greater_element(nums);
  for (auto n : result)
    cout << n << " ";
  cout << endl;
  return 0;
}
