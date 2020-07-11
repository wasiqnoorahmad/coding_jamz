/* This program implements task schedular given at:
 * https://leetcode.com/problems/task-scheduler/
 *
 */
#include <bits/stdc++.h>
using namespace std;

int least_interval(vector<char> &tasks, int n) {
  vector<int> char_map(26, 0);

  for (char c : tasks)
    char_map[c - 'A']++;

  sort(char_map.begin(), char_map.end());
  int max_freq = char_map[25] - 1, idle_slots = max_freq * n;

  for (int i = 24; i >= 0; i--)
    idle_slots -= min(char_map[i], max_freq);
  return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
}

int main(int argc, char const *argv[]) {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  printf("Minimum cycles are %d\n", least_interval(tasks, n));
  return 0;
}
