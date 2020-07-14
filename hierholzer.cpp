/* This program implements Hierholzer's algorithm which
  is used to detect Euler circuit in a directed graph.
  Program can be found at:
  https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/

  ** Hierholzer algorithm assumes that there is a eular path, and it prints that
  **

  Just to remember, we will have euler path/circuit in a graph if:

                          Eulerian Circuit        Eulerian Path

  Undirected Graph        Every vertex has        Either every vertex has even
                          an even degree.         degree or exactly two vertices
                                                  have odd degree.

  Directed Graph          Every vertex has        At most one vertex has
                          equal indegree and      outdegree - indegree = 1
                          outdegree.              and at most one vertex has
                                                  indegree - outdegree = 1
                                                  and all other vertices have
                                                  equal in and out degree.
 */

#include <bits/stdc++.h>
using namespace std;

void hierholzer(vector<vector<int>> &adj) {
  if (adj.size() == 0)
    return;

  unordered_map<int, int> edge_count;
  for (int i = 0; i < adj.size(); i++)
    edge_count[i] = adj[i].size();

  /* Stack to maintian the vertices */
  stack<int> curr_path;
  vector<int> circuit;

  curr_path.push(0);
  int curr_v = 0;

  while (!curr_path.empty()) {
    if (edge_count[curr_v]) {

      curr_path.push(curr_v);
      int next = adj[curr_v].back();
      edge_count[curr_v]--;
      adj[curr_v].pop_back();
      curr_v = next;

    } else {
      circuit.push_back(curr_v);
      curr_v = curr_path.top();
      curr_path.pop();
    }
  }

  for (int i = circuit.size() - 1; i >= 0; i--) {
    cout << circuit[i];
    if (i)
      cout << " -> ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> adj;
  adj.resize(7);
  adj[0].push_back(1);
  adj[0].push_back(6);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  adj[3].push_back(4);
  adj[4].push_back(2);
  adj[4].push_back(5);
  adj[5].push_back(0);
  adj[6].push_back(4);
  hierholzer(adj);

  return 0;
}
