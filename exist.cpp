/* This program solve the following problem:
 * https://leetcode.com/problems/word-search/ */

#include <bits/stdc++.h>

typedef std::vector<std::vector<char>> board_t;

bool dfs(board_t &board, int row, int col, int walk, std::string word) {
  if (walk == word.length())
    return true;

  if (row < 0 || row > board.size() - 1 || col < 0 || col > board[0].size() - 1)
    return false;

  if (board[row][col] == word[walk]) {
    char tmp = board[row][col];
    board[row][col] = '-';

    bool ans = dfs(board, row + 1, col, walk + 1, word) |
               dfs(board, row - 1, col, walk + 1, word) |
               dfs(board, row, col - 1, walk + 1, word) |
               dfs(board, row, col + 1, walk + 1, word);

    board[row][col] = tmp;
    return ans;
  }

  return false;
}

bool exist(board_t &board, std::string word) {
  bool found = false;
  int walk = 0;

  // Staring walking board
  for (int row = 0; row < board.size(); row++) {
    for (int col = 0; col < board[row].size(); col++) {
      if (board[row][col] == word[0] && dfs(board, row, col, walk, word))
        return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  board_t board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };

  // board_t board = {
  //     {'C', 'A', 'A'},
  //     {'A', 'A', 'A'},
  //     {'B', 'C', 'D'},
  // };

  std::string word = "ABCE";
  std::cout << exist(board, word) << std::endl;

  return 0;
}
