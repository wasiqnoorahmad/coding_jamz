/* This program finds the longest palindrome sub string. Question can be found
 * at: https://leetcode.com/problems/longest-palindromic-substring/ */

#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s) {
  int left = 0, right = s.length() - 1;

  while (left <= right) {
    if (s[left] != s[right]) return false;
    left++, right--;
  }
  return true;
}

string longest_palindrome(string s) {
  /* Exploting the fact that palindrom string starts and ends at the same
   * charactor */
  int left = 0, right = s.length() - 1;
  string max_sub = "";

  while (left < s.length()) {
    // find s[left] from right side
    right = s.length() - 1;
    while (left <= right) {
      if (s[left] == s[right]) {
        string sub = s.substr(left, right - left + 1);
        if (is_palindrome(sub)) {
          if (sub.length() > max_sub.length()) {
            max_sub = sub;
            // return max_sub;
          }
        }
      }
      right--;
    }

    left++;
  }
  return max_sub;
}

int main(int argc, char const *argv[]) {
  string src = "a";

  /* -> qahaq */

  string palin = longest_palindrome(src);
  cout << "Longest Palindrome string is " << palin << endl;
  return 0;
}
