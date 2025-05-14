#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
  void topoSort(vector<vector<pair<int, int>>> &adjList, stack<int> &st,
                vector<bool> &vis, int node) {
    vis[node] = true;
    for (auto &adjNode : adjList[node]) {
      if (!vis[adjNode.first]) {
        topoSort(adjList, st, vis, adjNode.first);
      }
    }
    st.push(node);
  }

public:
  vector<int> shortestPath(int N, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> adjList(N);
    for (auto &node : edges) {
      int u = node[0], v = node[1], wt = node[2];
      adjList[u].push_back({v, wt});
    }
    vector<bool> vis(N, false);
    stack<int> st;
    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        topoSort(adjList, st, vis, i);
      }
    }
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    while (!st.empty()) {
      int node = st.top();
      st.pop();
      for (auto it : adjList[node]) {
        int v = it.first, wt = it.second;
        if (dist[node] + wt < dist[v]) {
          dist[v] = dist[node] + wt;
        }
      }
    }
    for (auto &val : dist) {
      if (val == INT_MAX) {
        val = -1;
      }
    }
    return dist;
  }
};

int main() {
  int N = 6, M = 7;

  vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2},
                               {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
  Solution obj;
  vector<int> ans = obj.shortestPath(N, edges);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }

  return 0;
}
