/* This program finds the longest sub-string without repeating characters. Also
 * available at:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <bits/stdc++.h>

int longest_substr(std::string src) {
  std::unordered_map<char, int> map;
  int left = 0, right = 0, ans = 0;

  while (left <= right && right < src.length()) {
    if (map[src[right]] == 0) {
      map[src[right]]++;
      ans = std::max(ans, right - left + 1);
      right++;
    } else {
      map[src[left]]--;
      left++;
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  // std::string src = "abba";
  // std::string src = "abcabcbb";
  // std::string src = "dvdf";
  std::string src = "ohvhjdml";
  // std::string src = "vqblqcb";
  int len = longest_substr(src);
  printf("Longest Substring length is %d\n", len);
  return 0;
}
