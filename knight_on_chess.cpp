/* This program implements knight on chess board problem given at:
 * https://www.interviewbit.com/problems/knight-on-chess-board/ */

#include <bits/stdc++.h>
using namespace std;

typedef struct cell {
  int x, y, d;
  cell(int x, int y, int d) : x(x), y(y), d(d) {}
} cell;

bool is_inside(int x, int y, int row, int col) {
  if (x >= 1 && x <= row && y >= 1 && y <= col) return true;
  return false;
}

int knight(int row, int col, int curr_x, int curr_y, int dst_x, int dst_y) {
  bool visited[row + 1][col + 1];

  for (int i = 1; i <= row; i++)
    for (int j = 1; j <= col; j++) visited[i][j] = false;

  visited[curr_x][curr_y] = true;

  int x, y, dx[] = {1, 1, -1, -1, 2, 2, -2, -2},
            dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

  queue<cell> track;
  track.push(cell(curr_x, curr_y, 0));

  while (!track.empty()) {
    auto curr = track.front();
    track.pop();

    if (curr.x == dst_x && curr.y == dst_y) return curr.d;

    for (int i = 0; i < 8; i++) {
      x = curr.x + dx[i], y = curr.y + dy[i];

      if (is_inside(x, y, row, col) && !visited[x][y]) {
        visited[x][y] = true;
        track.push(cell(x, y, curr.d + 1));
      }
    }
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", knight(8, 8, 0, 0, 7, 7));  // 6
  // printf("%d\n", knight(4, 7, 1, 5, 1, 3));  // 2
  return 0;
}
