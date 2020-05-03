/* This program converts integer to roman. Statement can be found at:
 * https://leetcode.com/problems/integer-to-roman/ */

#include <bits/stdc++.h>
using namespace std;

string to_roman(int num) {
  string roman;
  while (num > 0) {
    if (num >= 1000) {
      roman += "M";
      num -= 1000;
    } else if (num >= 500) {
      if (num >= 900) {
        roman += "CM";
        num -= 900;
      } else {
        roman += "D";
        num -= 500;
      }
    } else if (num >= 100) {
      if (num >= 400) {
        roman += "CD";
        num -= 400;
      } else {
        roman += "C";
        num -= 100;
      }
    } else if (num >= 50) {
      if (num >= 90) {
        roman += "XC";
        num -= 90;
      } else {
        roman += "L";
        num -= 50;
      }

    } else if (num >= 10) {
      if (num >= 40) {
        roman += "XL";
        num -= 40;
      } else {
        roman += "X";
        num -= 10;
      }
    } else if (num >= 5) {
      if (num == 9) {
        roman += "IX";
        num -= 90;
      } else {
        roman += "V";
        num -= 5;
      }
    } else if (num >= 1) {
      switch (num) {
        case 1:
          roman += "I";
          break;
        case 2:
          roman += "II";
          break;
        case 3:
          roman += "III";
          break;
        case 4:
          roman += "IV";
          break;
      }
      num = 0;
    }
  }

  return roman;
}

int main(int argc, char const *argv[]) {
  string roman = to_roman(567);
  cout << roman << endl;
  return 0;
}
