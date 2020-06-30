/*
    This code prints all balanced parantheses of size N
 */

#include <string.h>

#include <iostream>
#include <stack>
#include <vector>

#define OPEN '('
#define CLOSE ')'

typedef std::stack<std::pair<std::string, int>> stack_t;

void parentheses(std::string src, int start, int end, int open, int close) {
  if (start == end && open != close)
    return;
  if (start == end) {
    std::cout << src << std::endl;
    return;
  }

  // Check if are balanced ...
  if (open == close) {
    src[start] = OPEN;
    parentheses(src, start + 1, end, open + 1, close);
  } else {
    src[start] = OPEN;
    parentheses(src, start + 1, end, open + 1, close);

    src[start] = CLOSE;
    parentheses(src, start + 1, end, open, close + 1);
  }
}

/* Parentheses function without recursion */
void _parentheses(int n) {
  stack_t bstack;
  bstack.push(std::make_pair("(", 1));

  while (!bstack.empty()) {
    auto src = bstack.top();
    bstack.pop();

    if (src.second < 0 || src.second > n)
      continue;

    if (src.first.length() == 2 * n) {
      if (src.second == 0) {
        std::cout << src.first << std::endl;
      }
      continue;
    }

    bstack.push(std::make_pair(src.first + "(", src.second + 1));
    bstack.push(std::make_pair(src.first + ")", src.second - 1));
  }
}

int main(int argc, char const *argv[]) {
  int n = 4;
  // std::string src;
  // src.resize(2 * n);
  // parantheses(src, 0, (2 * n), 0, 0);
  _parentheses(n);
  return 0;
}
