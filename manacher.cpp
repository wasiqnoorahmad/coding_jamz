/* This program implements Manacher's algorithm that is used to find the longest
 * palindrom string in O(n) */

#include <bits/stdc++.h>
using namespace std;

string get_modified(string src) {
  string dst;
  for (char c : src) {
    dst += ('#');
    dst += c;
  }
  dst += '#';
  return dst;
}

string manachers_algo(string src) {
  src = get_modified(src);
  // msf = maximum so far
  // msfi = maximum so far index
  int c = 0, r = 0, msf = 0, msfi = 0, mirror = 0;
  string long_palin;
  vector<int> P(src.length(), 0);

  for (int i = 0; i < src.length(); i++) {
    int mirror = (2 * c) - i;

    if (i < r) {
      P[i] = min(P[mirror], r - i);
    }

    // Expand at i
    int a = i + (1 + P[i]), b = i - (1 + P[i]);
    while (a < src.length() && b >= 0 && src[a] == src[b])
      P[i]++, a++, b--;

    if (i + P[i] > r) {
      c = i, r = i + P[i];

      if (P[i] > msf) {
        msf = P[i], msfi = i;
      }
    }
  }
  for (int i = msfi - msf; i <= msfi + msf; i++) {
    if (src[i] != '#')
      long_palin += src[i];
  }
  return long_palin;
}

int main(int argc, char const *argv[]) {
  string src = "babad";
  cout << manachers_algo(src) << endl;
  return 0;
}
