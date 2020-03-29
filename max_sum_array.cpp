// This problem is about finding the largest
// sum contiguous sub-array...

#include <iostream>
#include <vector>

int max_subarray(std::vector<int> A) {
  int curr_sum = 0, tmp_sum = 0;

  for (int walk = 0; walk < A.size(); walk++) {
    tmp_sum += A[walk];

    if (tmp_sum < 0) {
      tmp_sum = 0;
    } else if (tmp_sum > curr_sum) {
      curr_sum = tmp_sum;
    }
  }
  return curr_sum;
}

// This function will return the indexes of
// maximum sum sub-array ...
std::vector<int> max_subarray_indexes(std::vector<int> A) {
  std::vector<int> result;
  int curr_sum = 0, tmp_sum = 0, nxt_start = 0;
  int start = -1, end = 0;

  for (int walk = 0; walk < A.size(); walk++) {
    tmp_sum += A[walk];

    if (tmp_sum < 0) {
      tmp_sum = 0;
      nxt_start = walk + 1;
    } else if (tmp_sum > curr_sum) {
      curr_sum = tmp_sum;
      start = nxt_start;
      end = walk;
    }
  }

  result.push_back(start);
  result.push_back(end);
  return result;
}

void print_range(std::vector<int> A) {
  std::cout << "Start: " << A[0] << " | End : " << A[1] << std::endl;
}

int main(int argc, char const *argv[]) {
  // std::vector<int> A = {-2, -3, 4, -1, -2, 1, 5, -3};
  // std::vector<int> A = {-2, -3, 4, -1, -2, 1, 5, -3};
  // std::vector<int> A = {-2, -3, 4, -1, -2, 1, -5, 5, 5};
  // std::vector<int> A = {-1, 2, 3, -4, 5, 10};

  std::vector<int> A = {1, 3, -1};  // 1,2
  // std::vector<int> A = {-1};                                      //
  // null,null std::vector<int> A = {-1, -1, 1, -1, 1, -1, 1, 1, 1, -1};
  // // 3,9 std::vector<int> A = {1, -1, -1}; // 1,1
  // std::vector<int> A = {1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1};  // 5,11

  std::cout << max_subarray(A) << std::endl;
  print_range(max_subarray_indexes(A));
  return 0;
}
