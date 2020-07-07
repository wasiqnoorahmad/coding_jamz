/* Suppose you have a random list of people standing in a queue. Each person is
described by a pair of integers (h, k), where h is the height of the person and
k is the number of people in front of this person who have a height greater than
or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

#include <bits/stdc++.h>

#include "common.hpp"
using namespace std;

bool compare(vector<int> &A, vector<int> &B) {
  return (A[0] > B[0] || (A[0] == B[0] && A[1] < B[1]));
}

vector<vector<int>> reconstruct_queue(vector<vector<int>> &people) {
  sort(people.begin(), people.end(), compare);
  vector<vector<int>> result;
  for (vector<int> &v : people)
    result.insert(result.begin() + v[1], v);
  return result;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> result = reconstruct_queue(people);
  for (vector<int> &v : result)
    p_vector(v);

  return 0;
}
