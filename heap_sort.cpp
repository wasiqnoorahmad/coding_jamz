#include <vector>

#include "common.hpp"

/* left = (2 * i) | right = (2 * i) + 1 */

void heapify(std::vector<int> &arr, int size, int index) {
  int left = (2 * index), right = left + 1, max = index;

  if (left < size && arr[left] > arr[max])
    max = left;
  if (right < size && arr[right] > arr[max])
    max = right;

  if (max != index) {
    std::swap(arr[index], arr[max]);
    heapify(arr, size, max);
  }
}

void build_heap(std::vector<int> &arr, int size) {
  int start = (size / 2) + 1;

  while (start) {
    heapify(arr, size, start);
    start--;
  }
}

void heap_sort(std::vector<int> &arr, int size) {
  build_heap(arr, size);
  int end = size;

  while (end != 0) {
    std::swap(arr[1], arr[end]);
    heapify(arr, end - 1, 1);
    end--;
  }
}

int main(int argc, char const *argv[]) {
  std::vector<int> arr = {-1, 15, 41, 42, 80, 77, 37, 17, 0, 3, 5};

  p_vector(arr);
  heap_sort(arr, arr.size() - 1);
  p_vector(arr);

  return 0;
}
