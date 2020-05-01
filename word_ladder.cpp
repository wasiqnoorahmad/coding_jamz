/* This program implements word ladder 1 given at:
 * https://www.interviewbit.com/problems/word-ladder-i/ */

#include <bits/stdc++.h>
using namespace std;

const int hamming_dist(string &src, string &dst) {
  int walk = 0, diff = 0;

  while (walk < src.length()) {
    if (src[walk] != dst[walk]) diff++;
    walk++;
  }
  return diff;
}

int solve(string src, string target, vector<string> &dict) {
  int steps = 1, min_diff = INT_MAX, diff;
  string tmp = src, min_str;
  map<string, bool> selected;

  while (src != target) {
    if (hamming_dist(src, target) == 1) return steps + 1;

    min_diff = INT_MAX;

    for (string &word : dict) {
      if (word == src) continue;

      if (hamming_dist(word, src) == 1) {
        diff = hamming_dist(word, target);

        if (diff < min_diff) {
          min_diff = diff;
          min_str = word;
        }
      }
    }

    if (src == min_str) return 0;

    src = min_str;
    steps++;
  }

  return steps;
}

int main(int argc, char const *argv[]) {
  vector<string> dict = {"hot", "dot", "dog", "lot", "log"};
  printf("%d\n", solve("hit", "cog", dict));

  /* A : "ymain"
        B : "oecij"
        C : [ "ymann", "yycrj", "oecij", "ymcnj", "yzcrj", "yycij", "xecij",
     "yecij", "ymanj", "yzcnj", "ymain" ]  10 */
  return 0;
}
