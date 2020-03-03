#include <algorithm>
#include <iostream>

int cal_dist(int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    return abs(y2 - y1);
  }
  return abs(x2 - x1);
}

int min_steps(int A[], int B[], int size) {
  int len = size;

  int curr_x = A[0];
  int curr_y = B[0];
  int steps = 0;

  for (int i = 1; i < len; i++) {
    int next_x = A[i];
    int next_y = B[i];

    // Check if are in straight line
    if (curr_x == next_x || curr_y == next_y) {
      steps += cal_dist(curr_x, curr_y, next_x, next_y);
    } else {
      int diff = std::min(next_x - curr_x, next_y - curr_y);
      steps += abs(diff);
      curr_x += diff;
      curr_y += diff;
    }
  }
  return steps;
}

int main(int argc, char const *argv[]) {
  //   int A[] = {4, 8, -7, -5, -13, 9, -7, 8};
  //   int B[] = {4, -15, -10, -3, -13, 12, 8, -8};
  int A[] = {4, 8, -7};
  int B[] = {4, -15, -10};
  int size = sizeof(A) / sizeof(A[0]);

  std::cout << min_steps(A, B, size) << std::endl;
  return 0;
}
