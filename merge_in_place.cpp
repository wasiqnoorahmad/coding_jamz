#include <iostream>
#include <vector>

void merge_in_place(std::vector<int> &nums1, int m, std::vector<int> &nums2,
                    int n) {
  int end = m, left = 0, right = 0, fwalk = 0;

  while (left < end && right < n) {
    if (nums1[left] < nums2[right]) {
      left++;
    } else {
      fwalk = end;

      while (fwalk > left) {
        nums1[fwalk] = nums1[fwalk - 1];
        fwalk--;
      }
      nums1[left] = nums2[right];
      end++;
      right++;
      left++;
    }
  }

  while (right < n) {
    nums1[end++] = nums2[right++];
  }
}

void print_vec(std::vector<int> &A) {
  for (int v : A) {
    printf("%d, ", v);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  std::vector<int> num1 = {1};
  std::vector<int> num2 = {};
  merge_in_place(num1, 1, num2, num2.size());
  print_vec(num1);

  return 0;
}
