/* This program solve the problem of town judge:
In a town, there are N people labelled from 1 to N.  There is a rumor
   that one of these people is secretly the town judge.

        If the town judge exists, then:

                        1- The town judge trusts nobody.
                        2- Everybody (except for the town judge) trusts the town
   judge. 3- There is exactly one person that satisfies properties 1 and 2.

        You are given trust, an array of pairs trust{i} = {a, b} representing
   that the person labelled a trusts the person labelled b.

        If the town judge exists and can be identified, return the label of the
   town judge.  Otherwise, return -1
 */

#include <bits/stdc++.h>
using namespace std;

int town_judge(int N, vector<vector<int>> &trust) {
  int scores[N];
  memset(scores, 0, sizeof(scores));

  for (int i = 0; i < trust.size(); i++) {
    vector<int> &pair = trust[i];

    // Increase the score of trust
    if (scores[pair[1] - 1] != INT_MIN) {
      scores[pair[1] - 1] += 1;
    }
    scores[pair[0] - 1] = INT_MIN;
  }

  /* Find Max and Count */
  unordered_map<int, int> mp;
  int max = INT_MIN, index = -1;
  for (int i = 0; i < N; i++) {
    if (scores[i] > max)
      max = scores[i], index = i;
    mp[scores[i]]++;
  }

  if (index == -1 || mp[max] != 1 || scores[index] != N - 1)
    return -1;
  return index + 1;
}

int main(int argc, char const *argv[]) {
  // vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
  vector<vector<int>> trust = {{1, 2}};
  // vector<vector<int>> trust = {{1, 3}, {2, 3}, {3, 1}};
  // vector<vector<int>> trust = {{1, 2}, {2, 3}};

  int judge = town_judge(2, trust);
  cout << "Town judge is " << judge << endl;
  return 0;
}
