/*
    This code prints all balanced parantheses of size N
 */

#include <string.h>

#include <iostream>
#include <vector>

#define OPEN '('
#define CLOSE ')'

void parantheses(std::string src, int start, int end, int open, int close) {
  if (start == end && open != close) return;
  if (start == end) {
    std::cout << src << std::endl;
    return;
  }

  // Check if are balanced ...
  if (open == close) {
    src[start] = OPEN;
    parantheses(src, start + 1, end, open + 1, close);
  } else {
    src[start] = OPEN;
    parantheses(src, start + 1, end, open + 1, close);

    src[start] = CLOSE;
    parantheses(src, start + 1, end, open, close + 1);
  }
}

int main(int argc, char const *argv[]) {
  int n = 3;
  std::string src;
  src.resize(2 * n);
  parantheses(src, 0, (2 * n), 0, 0);
  return 0;
}
