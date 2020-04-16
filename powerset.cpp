/* This code prints all the sub-sets of a set */

#include <bits/stdc++.h>

void print_set(std::vector<int> &res) {
  printf("{");
  for (int val : res) {
    printf("%d ", val);
  }
  printf("}\n");
}

/* With recursion */
void all_sets(std::vector<int> &src, std::vector<int> &res, int index = 0) {
  if (index == src.size()) {
    print_set(res);
    return;
  }

  res.push_back(src[index]);
  all_sets(src, res, index + 1);
  res.pop_back();
  all_sets(src, res, index + 1);
}

/* Without recursion */
void all_sets(std::vector<int> &src) {
  std::vector<int> res;
  std::stack<int> track;
  int index = 0;
  track.push(index);

  while (!track.empty()) {
    index = track.top();
    track.pop();

    if (index == src.size()) {
      print_set(res);
      res.pop_back();
      continue;
    }

    res.push_back(src[index]);
    track.push(index + 1);
    track.push(index + 1);
  }
}

int main(int argc, char const *argv[]) {
  std::vector<int> src = {1, 2, 3};
  std::vector<int> res = {};
  all_sets(src, res);
  all_sets(src);

  return 0;
}