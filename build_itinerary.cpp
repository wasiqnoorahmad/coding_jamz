/* This program implements famous reconstruct itinerary problem given at :
 * https://leetcode.com/problems/reconstruct-itinerary/*/

#include <bits/stdc++.h>
using namespace std;

vector<string> find_itinerary(vector<vector<string>> &tickets) {
  vector<string> itinerary;

  if (tickets.size() == 0)
    return itinerary;

  unordered_map<string, multiset<string>> adj;
  for (int i = 0; i < tickets.size(); i++)
    adj[tickets[i][0]].insert(tickets[i][1]);

  stack<string> s;
  s.push("JFK");

  while (!s.empty()) {
    auto curr = s.top();
    if (adj[curr].empty()) {
      itinerary.push_back(curr);
      s.pop();
    } else {
      s.push(*(adj[curr].begin()));
      adj[curr].erase(adj[curr].begin());
    }
  }
  reverse(itinerary.begin(), itinerary.end());
  return itinerary;
}

int main(int argc, char const *argv[]) {
  vector<vector<string>> tickets = {
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

  vector<string> itinerary = find_itinerary(tickets);
  for (string i : itinerary)
    cout << i << " ";
  cout << endl;

  return 0;
}
