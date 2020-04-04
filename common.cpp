
#include "common.hpp"

#include <iostream>

void p_vector(std::vector<int>& A) {
  for (int v : A) {
    printf("%d, ", v);
  }
  printf("\n");
}