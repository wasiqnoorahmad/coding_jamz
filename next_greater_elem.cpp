/* This program solves the next greater element problem given at:
 * https://leetcode.com/problems/next-greater-element-i/ */
#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int> &nums1, vector<int> &nums2) {
  vector<int> res;
  stack<int> ss;
  unordered_map<int, int> mp;

  for (int i = nums2.size() - 1; i >= 0; i--) {
    if (ss.empty())
      mp.insert({nums2[i], -1});
    else {
      while (!ss.empty() && ss.top() <= nums2[i])
        ss.pop();

      if (ss.empty())
        mp.insert({nums2[i], -1});
      else
        mp.insert({nums2[i], ss.top()});
    }
    ss.push(nums2[i]);
  }

  for (auto x : nums1) {
    res.push_back((mp[x] == 0 ? -1 : mp[x]));
  }

  return res;
}

int main(int argc, char const *argv[]) {
  vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
  vector<int> r = next_greater_element(nums1, nums2);
  for (int a : r)
    cout << a << " ";
  cout << endl;
  return 0;
}
