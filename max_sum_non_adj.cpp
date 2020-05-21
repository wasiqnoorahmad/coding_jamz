/* This program calculates maximum sum in a positive array with adjacent
 * elements: Problem can be found at:
 * https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/ */

#include <bits/stdc++.h>
using namespace std;

int max_sum_no_adj(vector<vector<int>> arr) {
  int incl = 0, excl = 0, col_max = 0, tmp = 0, size = arr[0].size();

  for (int i = 0; i < size; i++) {
    col_max = max(arr[0][i], arr[1][i]);
    tmp = incl;
    incl = max(col_max + excl, incl);
    excl = tmp;
  }
  return incl;
}

int main(int argc, char const *argv[]) {
  // vector<vector<int>> arr = {{1, 4, 5}, {2, 0, 0}};
  vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
  int max = max_sum_no_adj(arr);
  printf("Maximum sum with adjacent elements is %d\n", max);
  return 0;
}
