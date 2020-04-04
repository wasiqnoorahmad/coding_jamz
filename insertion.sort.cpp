#include <vector>

#include "common.hpp"

void insert_sort(std::vector<int>& A) {
  if (A.size() <= 1) return;

  int start = 0, walk = 1, tmp_val = 0;

  while (walk < A.size()) {
    if (A[walk] < A[walk - 1]) {
      tmp_val = A[walk];
      start = walk - 1;
      while (start >= 0 && A[start] > tmp_val) {
        A[start + 1] = A[start];
        start--;
      }
      A[start + 1] = tmp_val;
    }
    walk++;
  }
}

int main(int argc, char const* argv[]) {
  std::vector<int> A = {-1, 3, 5, -9, 5};
  p_vector(A);
  insert_sort(A);
  p_vector(A);

  return 0;
}
