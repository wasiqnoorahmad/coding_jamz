/* This program implements floyd-warshall algorithm */
#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void print_2d(int dist[][V]) {
  cout << "The following matrix shows the shortest distances"
          " between every pair of vertices \n";
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF)
        cout << "INF"
             << "     ";
      else
        cout << dist[i][j] << "     ";
    }
    cout << endl;
  }
}

void floyd_warshall(int graph[][V]) {
  int dist[V][V];

  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      dist[i][j] = graph[i][j];

  /* All intermidiate nodes */
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  print_2d(dist);
}

int main(int argc, char const *argv[]) {
  /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
  int graph[V][V] = {
      {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};

  // Print the solution
  floyd_warshall(graph);
  return 0;
}
