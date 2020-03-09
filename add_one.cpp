#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<int> vector_int;

void print_vector(vector_int &A) {
  for (int i : A) {
    std::cout << i << "-> ";
  }
  std::cout << std::endl;
}

vector_int add_one_to_number(vector_int A) {
  // Walk until find first non-zero digit...
  int start = 0;
  int size = A.size();
  int carry = 1;
  int buf = 0;

  while (start < size - 1 && A[start] == 0) {
    start++;
  }

  vector_int result(size - start);
  int walk = size - 1;

  while (walk >= start) {
    result[walk - start] = A[walk] + carry;
    carry = result[walk - start] / 10;
    if (carry) {
      result[walk - start] = 0;
    }
    walk--;
  }

  // Shift one right if ends with zero
  if (result[0] == 0) {
    result.resize(size + 1);
    walk = result.size() - 1;
    while (walk > 0) {
      result[walk + 1] = result[walk];
      walk--;
    }
    result[0] = 1;
    result[1] = 0;
  }

  return result;
}

int main(int argc, char const *argv[]) {
  vector_int A = {9, 9, 9, 9, 9};
  print_vector(A);
  vector_int result = add_one_to_number(A);
  print_vector(result);
  return 0;
}
