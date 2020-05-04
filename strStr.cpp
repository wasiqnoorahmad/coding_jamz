/* This program implements needle in the haystack problem. Problem can be found
 * at: https://leetcode.com/problems/implement-strstr/submissions/  */

#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
  if (needle.length() == 0) return 0;
  int walk = 0, end = haystack.length() - needle.length() + 1;
  int start, foot, i = 0;

  while (walk < end) {
    i = 0;
    if (haystack[walk] == needle[i]) {
      start = walk, foot = start + needle.length();
      while (start < foot) {
        if (haystack[start] != needle[i]) break;
        i++, start++;
      }
      if (i == needle.length()) return walk;
    }
    walk++;
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  // printf("%d\n", strStr("aaa", "a"));
  printf("%d\n", strStr("hello", "ll"));
  return 0;
}
