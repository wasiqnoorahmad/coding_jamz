#include <iostream>

int missing(int arr[], int size) {
  // Value at index must be index - 1

  int right = size - 1, left = 0, mid = 0;

  while (right >= left) {
    mid = (left + right) / 2;

    if (arr[mid] != mid + 1 && arr[mid - 1] == mid) {
      return mid + 1;
    }

    else if (arr[mid] == mid + 1) {
      left = mid - 1;
    } else {
      right = mid + 1;
    }
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 6, 7, 8};
  int size = sizeof(arr) / sizeof(arr[0]);

  std::cout << missing(arr, size) << std::endl;

  return 0;
}
