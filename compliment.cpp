/* This program computes the compliment of a number */

#include <bits/stdc++.h>
using namespace std;

int compliment(int num) {
  int nb_bits = log2(num) + 1;
  uint64_t comp;

  comp = (1ULL << nb_bits) - 1;
  cout << "Comp = " << comp << endl;
  return (int)(comp) ^ num;
}

int main(int argc, char const *argv[]) {
  int num = 2147483647;
  printf("Complement of %d is %d\n", num, compliment(num));
  return 0;
}
