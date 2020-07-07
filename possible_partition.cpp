/* Given a set of N people (numbered 1, 2, ..., N), we would like to split
everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same
group.

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people
numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in
this way.

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

 */

#include <bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<vector<int>> &graph, vector<int> &color) {
  queue<int> q;
  color[node] = 1;
  q.push(node);

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    for (auto v : graph[u]) {
      if (!color[v]) {
        color[v] = -1 * color[u];
        q.push(v);
      }
      if (color[u] == color[v]) {
        return false;
      }
    }
  }
  return true;
}

bool possible_bipartition(int N, vector<vector<int>> &dislikes) {
  // Build a Graph
  vector<vector<int>> graph(N + 1);
  vector<int> color(N + 1, 0);

  for (int i = 0; i < dislikes.size(); i++) {
    auto dis = dislikes[i];
    graph[dis[0]].push_back(dis[1]);
    graph[dis[1]].push_back(dis[0]);
  }

  for (int i = 1; i <= N; i++) {
    if (!color[i] && !bfs(i, graph, color))
      return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  // int n = 4;
  // vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};

  // int n = 5;
  // vector<vector<int>> dislikes = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};

  int n = 3;
  vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 3}};

  if (possible_bipartition(n, dislikes))
    printf("True\n");
  else
    printf("False\n");

  return 0;
}
