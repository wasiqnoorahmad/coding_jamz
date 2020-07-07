/* This program checks if points in a vector make a straight line */
#include <bits/stdc++.h>
using namespace std;

bool is_straight_line(vector<vector<int>> &points) {
  if (points.size() <= 2)
    return true;

  float grad = INT_MAX, curr_grad = INT_MAX;
  vector<int> &p1 = points[0], &p2 = points[1];

  if (p2[0] - p1[0] != 0)
    grad = (float)(p2[1] - p1[1]) / (float)(p2[0] - p1[0]);

  printf("Grad = %f\n", grad);

  for (int i = 2; i < points.size(); i++) {
    p1 = points[i - 1], p2 = points[i];

    curr_grad = INT_MAX;
    if (p2[0] - p1[0] != 0)
      curr_grad = (float)(p2[1] - p1[1]) / (float)(p2[0] - p1[0]);

    printf("Curr Grad = %d\n", grad);

    if (curr_grad != grad)
      return false;
  }

  return true;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> points = {{-4, -3}, {1, 0}, {3, -1}, {0, -1}, {-5, 2}};
  if (is_straight_line(points))
    printf("True\n");
  else
    printf("False\n");
  return 0;
}
