/* This program converts a string into a number. Details can be found at:
 * https://leetcode.com/problems/string-to-integer-atoi
 */

#include <bits/stdc++.h>
using namespace std;

int my_atoi(string str) {
  if (!str.length())
    return 0;

  int walk = 0;
  bool is_negative = false;

  while (walk < str.length() && str[walk] == ' ')
    walk++;

  if (walk == str.length() || str[walk] < '0' || str[walk] > '9') {
    if (str[walk] == '+')
      walk++;
    else if (str[walk] == '-')
      walk++, is_negative = true;
    else
      return 0;
  }

  long num = 0;
  while (walk < str.length()) {
    if (str[walk] < '0' || str[walk] > '9')
      break;

    num *= 10;
    num += (str[walk] - '0');

    if (is_negative && num > INT_MAX)
      return INT_MIN;
    else if (num > INT_MAX)
      return INT_MAX;
    walk++;
  }
  if (is_negative)
    num *= -1;
  return num;
}

int main(int argc, char const *argv[]) {
  string src = "42";
  int num = my_atoi(src);
  printf("Converted Number is %d\n", num);
  return 0;
}
