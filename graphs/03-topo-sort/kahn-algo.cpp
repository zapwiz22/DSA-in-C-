#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// t.c. : O(V+E)
// s.c. : O(2V)
class Solution {
public:
  vector<int> kahnAlgo(int V, vector<vector<int>> &adjList) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
      for (auto &val : adjList[i]) {
        indegree[val]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }
    vector<int> topoSort;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      topoSort.push_back(node);
      for (auto &adjNode : adjList[node]) {
        indegree[adjNode]--;
        if (indegree[adjNode] == 0) {
          q.push(adjNode);
        }
      }
    }
    return topoSort;
  }
};

int main() {
  // V = 6;
  vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  int V = 6;
  Solution obj;
  vector<int> ans = obj.kahnAlgo(V, adj);

  for (auto node : ans) {
    cout << node << " ";
  }
  cout << endl;
  return 0;
}
