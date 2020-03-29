#include <climits>
#include <iostream>
#include <vector>

void foo(std::vector<int> &A) {
  int f = 0;
  for (int i = 0; i < A.size(); i++) {
    for (int j = i + 1; j < A.size(); j++) {
      f = std::abs(A[i] - A[j]) + std::abs((i + 1) - (j + 1));
      printf("f(%d, %d) = %d\n", i + 1, j + 1, f);
    }
  }
}

int max_abs_diff(std::vector<int> &A) {
  int walk = 0, max_1 = INT_MIN, max_2 = INT_MIN, min_1 = INT_MAX,
      min_2 = INT_MAX;

  while (walk < A.size()) {
    max_1 = std::max(max_1, A[walk] + walk);
    min_1 = std::min(min_1, A[walk] + walk);

    max_2 = std::max(max_2, A[walk] - walk);
    min_2 = std::min(min_2, A[walk] - walk);

    walk++;
  }

  return std::max(max_1 - min_1, max_2 - min_2);
}

int main(int argc, char const *argv[]) {
  std::vector<int> A = {19, 65, 42, 66, -44, 45, -42, 17, -52, -59};
  std::cout << max_abs_diff(A) << std::endl;
  return 0;
}
