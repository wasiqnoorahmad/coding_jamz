/* This program implements word ladder 1 given at:
 * https://www.interviewbit.com/problems/word-ladder-i/ */

#include <bits/stdc++.h>
using namespace std;

const bool is_reachable(string src, string dst) {
  int walk = 0, diff = 0;
  while (walk != src.length()) {
    if (src[walk] != dst[walk]) diff++;
    walk++;
  }
  return diff == 1;
}

int solve(string src, string target, vector<string> &dict) {
  if (src == target) return 1;
  if (is_reachable(src, target)) return 2;

  /* Here goes the BFS */
  vector<bool> visited(dict.size(), false);
  queue<pair<int, string>> track;
  track.push(make_pair(1, src));

  while (!track.empty()) {
    auto curr = track.front();
    track.pop();

    if (is_reachable(curr.second, target)) return curr.first + 1;

    for (int walk = 0; walk < dict.size(); walk++) {
      if (!visited[walk] && is_reachable(curr.second, dict[walk])) {
        visited[walk] = true;
        track.push(make_pair(curr.first + 1, dict[walk]));
      }
    }
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  vector<string> dict = {"hot", "dot", "dog", "lot", "log"};
  printf("%d\n", solve("hit", "cog", dict));

  // vector<string> dict = {"ymann", "yycrj", "oecij", "ymcnj", "yzcrj",
  // "yycij",
  //                        "xecij", "yecij", "ymanj", "yzcnj", "ymain"};
  // printf("%d\n", solve("ymain", "oecij", dict));  // 10

  // vector<string> dict = {
  //     "mzqwkyfqdfkkhdtrwmxm", "mlqdryzxdwukhdtpqqkv", "pyudlolywuuiexfdqevw",
  //     "mzqwrylbdfkkhdtfbqxm", "yyudloxxvwumevoyqqyw", "yyqdfozevwumedoyqqyk",
  //     "nzqwkyfqdfkkhdtywmkm", "yyqdfozevwumedowqqyv", "uhoddciyreuihqftqvjl",
  //     "mzqwryzbdfkkhdtfbqxm", "yyudfozxvwumevoyqqyk", "pyndlciyuuuieqftqvjl",
  //     "mzqdryzxdwkkhdtpqqxm", "ylqduozxvwumedowqqyv", "mzqwkyfqdfkkhdtfwqxm",
  //     "pyndlciyuuuieqfhqvjl", "nlqduyzxvwumedopqqqv", "pyudlolywuuiexfhqevw",
  //     "uhojdciyrnughwfiqvil", "mzqwkyfqdfkkhdtrwqxm", "yyqdfozevwumevoyqqyk",
  //     "pyodlciyuruiyqftqvjl", "pyudlciyuuuiexfhqevw", "mzqwrylqdfkkhdtfbqxm",
  //     "nlqdryzxdwukhdtpqqkv", "uhoddciyreughwftqvil", "nlqduozxvwumedowqqyv",
  //     "pyudlclywuuiexfhqevw", "nlqduyzxdwukedopqqqv", "hzqxcydbdxkkcdtzwgkm",
  //     "pyudlciyuuuieffhqevw", "pyudlolyvwuiexodqevw", "uhoddciyreughwftqvjl",
  //     "nzqwcyfbdxkkhdtzwmkm", "pyodlciyuuuiyqftqvjl", "nlqduyzxdwukhdtpqqkv",
  //     "fyudloxyvwumevoyqqyw", "uhojdciyreughwfiqvil", "mzqwkyfqdfkkhdtfbqxm",
  //     "nzqwcyfqdfkkhdtzwmkm", "pyudlciyuuuiebfhqvjl", "pyoddciyaeuihqftqvjl",
  //     "yyqdfozpvwumedowqqyv", "nzqwcydbdxkkhdtzwmkm", "mzqwryzbdwkkhdtpbqxm",
  //     "pyudloxyvwuievodqeyw", "fyudloxyvwumevodqqyw", "pyodlciyuuuieqftqvjl",
  //     "yyudfozevwumevoyqqyk", "yyqdfozevwumedowqqyk", "hzqwcydbdxkkcdtzwgkm",
  //     "mzqwkyfqdfkkhdtywmxm", "nzqwcydbdxkkcdtzwgkm", "nlqdubzxvwumedopqqyv",
  //     "pyudlolyvuuiexfdqevw", "yyudloxyvwumevoyqqyw", "yyudlozxvwumevoyqqyw",
  //     "pyudlciyuuuiebfhqvjw", "mzqwkylqdfkkhdtfbqxm", "mkqdryzxdwukhdtpqqkv",
  //     "hzqxcydbdxkbcdtzwgkm", "nzqwqyfqdfkkhdtzwmkm", "mzqwryzzdwkkhdtpqqxm",
  //     "fyudloxyvwumevodqeyw", "mzqdryzzdwkkhdtpqqxm", "pyudlciyuuuiebfhqevw",
  //     "pyodlciyueuiyqftqvjl", "nlqduyzxvwukedopqqqv", "nlqdubzxvwumedowqqyv",
  //     "mzqwkyfqdfkkhdtywmkm", "phoddciyreuihqftqvjl", "ylqduozpvwumedowqqyv",
  //     "pyoddciyaeuiyqftqvjl", "nlqduyzxdwukhdtpqqqv", "uhoddciyreuihwftqvjl",
  //     "yyudlozxvwumevoyqqyk", "nlqduyzxdwukhdopqqqv", "pyudlciywuuiexfhqevw",
  //     "pyudloxyvwuiexodqeyw", "mzqwryzbdfkkhdtpbqxm", "nzqwkyfqdfkkhdtzwmkm",
  //     "nzqwcyfbdfkkhdtzwmkm", "meqdryzxdwukhdtpqqkm", "mzqwryzbdwkkhdtpqqxm",
  //     "nzqwcydbdxkkcdtzwmkm", "pyudloxyvwuiexodqevw", "fyudloxyvwuievodqeyw",
  //     "pyudlolyvuuiexodqevw", "mzqdryzxdwukhdtpqqxm", "pyudlciyuuuieqfhqvjl",
  //     "meqdryzxdwukhdtpqqkv", "uhoddciyreughwfiqvil", "pyodlciyaeuiyqftqvjl",
  //     "nlqdubzxvwumedopqqqv", "meqdryzxdwukhdtpqqxm", "yyqduozpvwumedowqqyv",
  //     "pyudlciyuuuiebfhqejw", "phoddciyaeuihqftqvjl"};
  // printf("%d\n",
  //        solve("hzqxcydbdxkbcdtzwgkm", "uhojdciyrnughwfiqvil", dict));  // 94

  return 0;
}
