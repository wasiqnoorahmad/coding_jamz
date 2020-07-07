#include <stdlib.h>

#include <iostream>

int pow(int x, int n, int d) {
  if (n == 0)
    return (1 % d);
  long long prod = 1;
  x = x % d;

  while (n > 0) {
    if (n % 2 == 1) {
      prod = (prod * (long long)x) % (long long)d;
    }
    x = ((long long)x * (long long)x) % (long long)d;
    n = n / 2;
  }
  return (int)(d + prod) % d;
}

int main(int argc, char const *argv[]) {
  // int p = pow(79161127, 99046373, 57263970);  // 47168647
  // int p = pow(71045970, 41535484, 64735492);  // 20805472

  // int p = pow(10, 0, 1);  // 0
  int p = pow(-1, 1, 20); // 1
  // int p = pow(10, 0, 3);  // 1
  // int p = pow(0, 0, 1); // 0

  std::cout << p << std::endl;
  return 0;
}