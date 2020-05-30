/* We write the integers of A and B (in the order they are given) on two
separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i]
and B[j] such that:

    A[i] == B[j];
    The line we draw does not intersect any other connecting (non-horizontal)
line.

Note that a connecting lines cannot intersect even at the endpoints: each number
can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

Example 2:
Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3

Example 3:
Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int max_uncrossed_lines(vector<int>& A, vector<int>& B) {
  int dp[A.size() + 1][B.size() + 1];

  for (int i = 0; i <= A.size(); i++) {
    for (int j = 0; j <= B.size(); j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (A[i - 1] == B[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[A.size()][B.size()];
}

int main(int argc, char const* argv[]) {
  vector<int> A = {2, 5, 1, 2, 5};
  vector<int> B = {10, 5, 2, 1, 5, 2};
  printf("Max Uncrossed Lines %d\n", max_uncrossed_lines(A, B));
  return 0;
}
