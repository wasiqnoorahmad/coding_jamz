/* This program returns K mins from a list of numbers */
#include <bits/stdc++.h>

#include "common.hpp"
using namespace std;

vector<int> k_mins(int K, vector<int> &nums) {
  priority_queue<int, vector<int>, greater<int> > pq;

  for (int i = 0; i < nums.size(); i++) {
    pq.push(nums[i]);
  }

  vector<int> result;

  for (int i = 0; i < K; i++) {
    result.push_back(pq.top());
    pq.pop();
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int K = 3;
  vector<int> nums = {30, 50, 10, 40, 60, 20};
  vector<int> mins = k_mins(K, nums);
  p_vector(mins);
  return 0;
}
