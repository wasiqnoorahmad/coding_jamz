/* There are a total of numCourses courses you have to take, labeled from 0 to
numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it
possible for you to finish all courses?



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is
possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take
course 0 you should also have finished course 1. So it is impossible.
 */

#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>> &graph, vector<int> &visited) {
  visited[u] = 0;

  for (auto v : graph[u]) {
    if (visited[v] == 0)
      return false;
    else if (visited[v] == -1 && !dfs(v, graph, visited))
      return false;
  }
  visited[u] = 1;
  return true;
}

bool can_finish(int num, vector<vector<int>> &prerequisites) {
  vector<vector<int>> graph(num);

  for (auto pre : prerequisites) graph[pre[0]].push_back(pre[1]);

  vector<int> visited(num, -1);

  // -1 = Not Visited
  //  0 = In stack
  //  1 = Visited

  for (int i = 0; i < num; i++) {
    if (visited[i] != -1)
      continue;
    else if (!dfs(i, graph, visited))
      return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  // int num = 2;
  // vector<vector<int>> prerequisites = {{1, 0}};
  // true

  // int num = 2;
  // vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  // false

  int num = 3;
  vector<vector<int>> prerequisites = {{0, 1}, {0, 2}, {1, 2}};
  /* True */

  // int num = 4;
  // vector<vector<int>> prerequisites = {{0, 1}, {3, 1}, {1, 3}, {3, 2}};

  if (can_finish(num, prerequisites))
    printf("true\n");
  else
    printf("false\n");

  return 0;
}
