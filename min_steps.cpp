#include <algorithm>
#include <iostream>

int cal_dist(int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    return abs(y2 - y1);
  }
  return abs(x2 - x1);
}

int get_direct(int src, int dst) {
  if (dst > src)
    return 1;
  if (dst < src)
    return -1;
}

int min_steps(int A[], int B[], int size) {
  int len = size;

  // Consider yourself starting at the first point ...
  int curr_x = A[0];
  int curr_y = B[0];
  int steps = 0;

  // Consider next destination starting from second point ...
  for (int i = 1; i < len; i++) {
    int next_x = A[i];
    int next_y = B[i];

    // Check if starting position and destination are in straight line ...
    if (curr_x == next_x || curr_y == next_y) {
      // Calculate the straight line distance ...
      steps += cal_dist(curr_x, curr_y, next_x, next_y);
      curr_x = next_x;
      curr_y = next_y;
    } else {
      // Otherwise, calculate the diagonal distance to reach
      // nearest point which lies in straight line to the destination ...
      int diff = std::min(abs(next_x - curr_x), abs(next_y - curr_y));
      steps += abs(diff);
      // Update current position to nearest point lying
      // in straight line to destination...
      curr_x += get_direct(curr_x, next_x) * diff;
      curr_y += get_direct(curr_y, next_y) * diff;

      // Calculate the straight line distance ...
      steps += cal_dist(curr_x, curr_y, next_x, next_y);
      curr_x = next_x;
      curr_y = next_y;
    }
  }
  return steps;
}

int main(int argc, char const *argv[]) {
  // int A[] = {4, 8, -7, -5, -13, 9, -7, 8};
  // int B[] = {4, -15, -10, -3, -13, 12, 8, -8};
  int A[] = {-5, 7,  -12, 4,  -6,  2,  -5, -12, -6, 3,
             11, 10, -8,  11, -13, -8, 5,  -12, 4,  4};
  int B[] = {-6, 6,  -8, -13, -2, -9,  -10, -10, -7, -14,
             9,  -8, -4, 8,   13, -11, 13,  5,   9,  11};
  int size = sizeof(A) / sizeof(A[0]);

  std::cout << min_steps(A, B, size) << std::endl;
  return 0;
}
