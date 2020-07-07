/* Given two strings s1 and s2, write a function to return true if s2 contains
the permutation of s1. In other words, one of the first string's permutations is
the substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 */

#include <bits/stdc++.h>

#include "common.hpp"
using namespace std;

bool check_inclusion(string s1, string s2) {
  vector<int> s1_count(26, 0), s2_count(26, 0);

  for (int i = 0; i < s1.length(); i++)
    s1_count[s1[i] - 'a']++, s2_count[s2[i] - 'a']++;

  if (s1_count == s2_count)
    return true;

  for (int i = s1.length(); i < s2.length(); i++) {
    s2_count[s2[i] - 'a']++;
    s2_count[s2[i - s1.length()] - 'a']--;

    if (s1_count == s2_count)
      return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  string s1 = "ab";
  string s2 = "eidbaoo";

  if (check_inclusion(s1, s2))
    cout << "True\n";
  else
    cout << "False\n";
  return 0;
}
