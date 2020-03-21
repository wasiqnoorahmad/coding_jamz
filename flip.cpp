#include <iostream>
#include <string>
#include <vector>

std::vector<int> flip(std::string A) {
  // Idea is to convert 1 to -1 and 0 to 1, so that
  // we get maximum sum sub-string where 0 are preferred ..
  std::vector<int> result;

  int walk = 0, tmp_sum = 0, curr_sum = 0, end = A.length();
  int left = -1, right = -1, nxt_start = 0;

  while (walk < end) {
    if (A[walk] == '1') {
      tmp_sum += -1;
    } else {
      tmp_sum += 1;
    }

    if (tmp_sum < 0) {
      tmp_sum = 0;
      nxt_start = walk + 1;
    } else if (tmp_sum > curr_sum) {
      curr_sum = tmp_sum;

      left = nxt_start;
      right = walk;
    }
    walk++;
  }

  if (left != -1) {
    result.push_back(left + 1);
    result.push_back(right + 1);
  }
  return result;
}

void print_vector(std::vector<int> &A) {
  for (int i : A) {
    std::cout << i << "->";
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
  // std::vector<int> res = flip(std::string("0011101")); // 1,2
  // std::vector<int> res = flip(std::string("11"));
  // std::vector<int> res = flip(std::string("1101010001"));  // 3,9
  // std::vector<int> res = flip(std::string("010")); // 1,1
  // std::vector<int> res = flip(std::string("0111000100010"));  // 5,11
  std::vector<int> res = flip(std::string("11110000000"));    // 5,11
  print_vector(res);
  return 0;
}
