#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// only applicable in DAG (directed acyclic graphs)
// in topological sorting node u will appear before v if there is a directed
// edge from u->v
class Solution {
public:
  vector<int> topoSort(int V, vector<vector<int>> &adjList) {
    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(i, adjList, vis, st);
      }
    }
    vector<int> res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    return res;
  }

private:
  void dfs(int src, vector<vector<int>> &adjList, vector<bool> &vis,
           stack<int> &st) {
    vis[src] = true;
    for (auto &adjNode : adjList[src]) {
      if (!vis[adjNode]) {
        dfs(adjNode, adjList, vis, st);
      }
    }
    st.push(src);
  }
};

int main() {
  // V = 6;
  vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  int V = 6;
  Solution obj;
  vector<int> ans = obj.topoSort(V, adj);

  for (auto node : ans) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
