/* Given a non-negative integer num represented as a string, remove k digits
from the number so that the new number is the smallest possible.

Note:

    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.

    Input: num = "1432219", k = 3
    Output: "1219"
 */

#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

void rec_remove_K_digits(string num, int k, string &res) {
  if (k == 0) {
    res.append(num);
    return;
  }

  int len = num.length();
  if (k >= len) return;

  int mi = 0;
  for (int i = 1; i <= k; i++)
    if (num[i] < num[mi]) mi = i;

  res.push_back(num[mi]);

  string new_str = num.substr(mi + 1);
  rec_remove_K_digits(new_str, k - mi, res);
}

string remove_K_digits(string num, int k) {
  string res = "";
  rec_remove_K_digits(num, k, res);

  /* Remove starting zeros */
  int i = 0;
  while (i < res.length() && res[i] == '0') i++;

  res = res.substr(i);
  if (res.length() == 0) res = "0";
  return res;
}

int main(int argc, char const *argv[]) {
  string num = "10200";
  int k = 1;
  cout << remove_K_digits(num, k) << endl;
  return 0;
}
