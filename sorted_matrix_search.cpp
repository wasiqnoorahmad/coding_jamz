/* This program searches in a sorted 2D matrix.
  Problem can be found at: https://leetcode.com/problems/search-a-2d-matrix-ii/
 */
#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &m, int target) {
  /*
    Start from top left corner
    if elemet == target
      return
    if target > element
      delete row
    else
      delete col
   */
  if (m.size() == 0)
    return false;

  int r = 0, c = m[0].size() - 1;

  while (r < m.size() && c >= 0) {
    // cout << "Searching r = " << r << " c = " << c << endl;
    if (m[r][c] == target)
      return true;

    if (target > m[r][c])
      r++;
    else
      c--;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int t = 0;
  vector<vector<int>> m = {{1, 4, 7, 11, 15},
                           {2, 5, 8, 12, 19},
                           {3, 6, 9, 16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}};
  if (search(m, t))
    printf("Element found\n");
  else
    printf("Element not found\n");
  return 0;
}
