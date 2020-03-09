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
  vector_int result(A);

  int carry = 0;
  int right = A.size() - 1;

  result[right] = A[right] + 1;

  for (right = right - 1; right >= 0; right--) {
    carry = 0;
    if (result[right + 1] > 9) {
      result[right + 1] = 0;
      carry = 1;
    }
    result[right] = A[right] + carry;
  }

  while (result[0] == 0) {
    for (int i = 1; i < result.size(); i++) {
      result[i - 1] = result[i];
    }
    result.erase(result.end() - 1);
  }

  if (result[0] == 10) {
    result[0] = 0;
    result.resize(result.size() + 1);
    for (int i = result.size() - 1; i >= 0; i--) {
      result[i + 1] = result[i];
    }
    result[0] = 1;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  vector_int A = {0, 0, 4, 4, 6, 0, 9, 6, 5, 1 };
  vector_int result = add_one_to_number(A);
  print_vector(A);
  print_vector(result);
  return 0;
}
