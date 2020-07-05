/* This program implements Dijkstra's algorithm */

#include <bits/stdc++.h>

// Number of vertices in the graph
#define V 9

void solution(int dist[]) {
  printf("Vertex \t\t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

void initialize(int dist[], bool visited[], int src) {
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, visited[i] = false;
  dist[src] = 0;
}

int min_distance(int dist[], bool visited[]) {
  int min_indx = 0, min_dist = INT_MAX;

  for (int i = 0; i < V; i++) {
    if (visited[i] == false && dist[i] <= min_dist)
      min_dist = dist[i], min_indx = i;
  }
  return min_indx;
}

void dijkstra(int graph[V][V], int src) {
  /* An array to keep shortest distances from src*/
  int dist[V];
  /* An array to keep track of vertices that has been visited */
  bool visited[V];

  /* Initialize distance and visited nodes */
  initialize(dist, visited, src);

  /* Now calculate shortest paths for all nodes */
  for (int i = 0; i < V; i++) {
    /* Get the nearest vertex from here */
    int u = min_distance(dist, visited);

    visited[u] = true;

    /* Relax all edges from nearest */
    for (int v = 0; v < V; v++) {
      if (visited[v] == false && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
    }
  }

  solution(dist);
}

int main() {
  int graph[V][V] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}};

  dijkstra(graph, 0);
  return 0;
}
