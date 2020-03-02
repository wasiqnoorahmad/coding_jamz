#include <iostream>

int main(int argc, char const *argv[]) {
  int first = 6, second = 0, third = 4;

  int max = (first > second) * first + (second > first) * second;
  max = (third > max) * third + (max > third) * max;

  int min = (first < second) * first + (second < first) * second;
  min = (third < min) * third + (min < third) * min;

  int mid = (first + second + third) - (max + min);

  std::cout << "Max: " << max << " Mid: " << mid << " Min: " << min << std::endl;
  return 0;
}
