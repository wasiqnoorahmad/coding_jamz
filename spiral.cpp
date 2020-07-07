/* This program travels a 2D grid in spiral mode.
 * Problem can be found at: https://leetcode.com/problems/spiral-matrix/
 */

#include <bits/stdc++.h>

#include "common.hpp"

typedef std::vector<std::vector<int>> grid_t;

int walk_row(grid_t &matrix, int row, int c_start, int c_end,
             std::vector<int> &result) {
  /* If only one cell */
  if (c_start == c_end) {
    result.push_back(matrix[row][c_start]);
    return 1;
  }

  int increment = c_start < c_end ? 1 : -1;
  int steps = 0;
  while (c_start != c_end) {
    result.push_back(matrix[row][c_start]);
    c_start += increment;
    steps++;
  }

  result.push_back(matrix[row][c_start]);
  return steps + 1;
}

int walk_col(grid_t &matrix, int col, int r_start, int r_end,
             std::vector<int> &result) {
  /* If only one cell */
  if (r_start == r_end) {
    result.push_back(matrix[r_start][col]);
    return 1;
  }

  int increment = r_start < r_end ? 1 : -1;
  int steps = 0;
  while (r_start != r_end) {
    result.push_back(matrix[r_start][col]);
    r_start += increment;
    steps++;
  }

  result.push_back(matrix[r_start][col]);
  return steps + 1;
}

std::vector<int> spiral(grid_t &matrix) {
  std::vector<int> result;

  int nb_rows = matrix.size();
  if (nb_rows == 0)
    return result;
  int nb_cols = matrix[0].size();
  if (nb_cols == 0)
    return result;

  /* Here goes the code */
  int s_row = 0, e_row = nb_rows - 1, s_col = 0, e_col = nb_cols - 1;
  int steps = 0;

  while (steps != nb_rows * nb_cols) {
    /* Going Right */
    if (steps != nb_rows * nb_cols && s_col <= e_col) {
      steps += walk_row(matrix, s_row, s_col, e_col, result);
    }
    s_row++;
    /* Going Down */
    if (steps != nb_rows * nb_cols && s_row <= e_row) {
      steps += walk_col(matrix, e_col, s_row, e_row, result);
    }
    e_col--;
    /* Going Left */
    if (steps != nb_rows * nb_cols && e_col >= s_col) {
      steps += walk_row(matrix, e_row, e_col, s_col, result);
    }
    e_row--;
    /* Going up */
    if (steps != nb_rows * nb_cols && e_row >= s_row) {
      steps += walk_col(matrix, s_col, e_row, s_row, result);
    }
    s_col++;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  grid_t matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
  };

  // grid_t matrix = {
  //     {1, 2, 3, 4},
  //     {5, 6, 7, 8},
  //     {9, 1, 2, 3},
  // };

  // grid_t matrix = {
  //     {6, 9, 7},
  // };

  // grid_t matrix = {
  //     {1, 2, 3},
  //     {4, 5, 6},
  //     {7, 8, 9},
  // };

  std::vector<int> result = spiral(matrix);
  p_vector(result);
  return 0;
}
