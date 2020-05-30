/* Given a m * n matrix of ones and zeros, return how many square submatrices
 * have all ones.
 * Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
 */

#include <bits/stdc++.h>
using namespace std;

int count_squares(vector<vector<int>>& matrix) {
  int count = 0;

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == 1 && i > 0 && j > 0) {
        matrix[i][j] =
            min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
      }
      count += matrix[i][j];
    }
  }

  return count;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> matrix = {
      {0, 1},
      {1, 1},
  };
  printf("%d\n", count_squares(matrix));
  return 0;
}
