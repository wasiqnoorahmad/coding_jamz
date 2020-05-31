/* Given a binary array, find the maximum length of a contiguous subarray with
equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0
and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

#include <bits/stdc++.h>
using namespace std;

int contigous_arr(vector<int>& nums) {
  unordered_map<int, int> m;
  int sum = 0, length = 0;

  m[0] = -1;

  for (int i = 0; i < nums.size(); i++) {
    sum += (nums[i] == 0) ? -1 : 1;

    if (m.find(sum) != m.end()) {
      if (length < i - m[sum]) {
        length = i - m[sum];
      }
    } else {
      m[sum] = i;
    }
  }
  return length;
}

int main(int argc, char const* argv[]) {
  vector<int> nums = {0, 0, 1, 0, 0, 0, 1, 1};
  printf("%d\n", contigous_arr(nums));
  return 0;
}
