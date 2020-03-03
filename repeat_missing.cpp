#include <bits/stdc++.h>
#include <iostream>

void repeat_missing(int arr[], int size) {
  int repeat = -1, missing = -1;
  int jump = 0;

  // Find Repeat ...
  for (int i = 0; i < size; i++) {
    jump = abs(arr[i]) - 1;
    if (arr[jump] > 0) {
      arr[jump] *= -1;
    } else {
      repeat = jump + 1;
    }
  }

  // Find Missing ...
  for (int i = 0; i < size; i++) {
    if (arr[i] > 0) {
      missing = i + 1;
    }
  }

  std::cout << "Repeat " << repeat << std::endl;
  std::cout << "Missing " << missing << std::endl;
}

int main(int argc, char const *argv[]) {
  int arr[] = {7, 3, 4, 5, 5, 6, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  repeat_missing(arr, n);

  return 0;
}
