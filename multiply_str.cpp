/* This program multiple two string, and return answer in a strign as well.
 * Problem can be found at:
 * https://leetcode.com/problems/multiply-strings/submissions/ */

#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
  if (num2.length() > num1.length())
    swap(num1, num2);
  if (num1 == "0" || num2 == "0")
    return string("0");

  int nb_rows = 1 + max(num1.length(), num2.length()),
      nb_cols = num1.length() + num2.length(), grid[nb_rows][nb_cols];

  /* Fill with zeros */
  for (int i = 0; i < nb_rows; i++)
    for (int j = 0; j < nb_cols; j++)
      grid[i][j] = 0;

  int prod = 1, carry = 0, foot = 1, curr_row = 0, curr_col = 0;

  for (int i = num2.length() - 1; i >= 0; i--) {
    curr_col = nb_cols - foot;
    for (int j = num1.length() - 1; j >= 0; j--) {
      prod = carry + ((int)(num2[i] - '0') * (int)(num1[j] - '0'));
      grid[curr_row][curr_col] = prod % 10;
      carry = prod / 10;
      curr_col--;
    }
    if (carry) {
      grid[curr_row][curr_col] = carry;
      carry = 0;
    }
    curr_row++;
    foot++;
  }

  /* Print grid */
  for (int i = 0; i < nb_rows; i++) {
    for (int j = 0; j < nb_cols; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  /* Gather sums */
  int sum = 0;
  char val;
  string result;

  for (int j = nb_cols - 1; j >= 0; j--) {
    sum = 0;
    for (int i = 0; i < nb_rows; i++) {
      sum += grid[i][j];
    }
    sum += carry;
    // printf("Sum is %d, ", sum);
    val = (char)(sum % 10) + '0';
    // printf("Val is %c\n", val);
    result = val + result;
    carry = sum / 10;
  }
  if (carry)
    result = (char)(carry + '0') + result;
  if (result[0] == '0')
    result = result.substr(1);
  return result;
}

int main(int argc, char const *argv[]) {
  cout << multiply("999", "0") << endl;
  return 0;
}
