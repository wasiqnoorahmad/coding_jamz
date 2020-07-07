/* This program adds two strings and returns the sum in a string as well */
#include <bits/stdc++.h>
using namespace std;

string add_strings(string num1, string num2) {
  if (num1.length() < num2.length())
    swap(num1, num2);

  int left = num1.length() - 1, right = num2.length() - 1, sum, carry = 0;
  string result;

  while (left >= 0 && right >= 0) {
    sum = carry + ((int)(num1[left] - '0') + (int)(num2[right] - '0'));
    result = (char)((sum % 10) + '0') + result;
    carry = sum / 10;
    right--, left--;
  }

  while (left >= 0) {
    sum = carry + (int)(num1[left] - '0');
    result = (char)((sum % 10) + '0') + result;
    carry = sum / 10;
    left--;
  }

  if (carry)
    result = (char)(carry + '0') + result;
  return result;
}

int main(int argc, char const *argv[]) {
  cout << add_strings("9", "99") << endl;
  return 0;
}
