#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// shrotest path in undirected graph with unit distances between nodes
// simple bfs traversal will do it
class Solution {
public:
  vector<int> shortestPath(vector<vector<int>> &adjList, int V, int src) {
    vector<int> dist(V, INT_MAX); // distance from the source node
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto &adjNode : adjList[node]) {
        if (dist[node] + 1 < dist[adjNode]) {
          dist[adjNode] = dist[node] + 1;
          q.push(adjNode);
        }
      }
    }
    for (auto &val : dist) {
      if (val == INT_MAX) {
        val = -1; // unreachable
      }
    }
    return dist;
  }
};

int main() {
  Solution ans;
  vector<vector<int>> adj = {{
                                 1,
                                 3,
                             },
                             {0, 2},
                             {1, 6},
                             {0, 4},
                             {3, 5},
                             {4, 6},
                             {2, 5, 7, 8},
                             {6, 8},
                             {6, 7}};
  int N = 9;
  vector<int> res = ans.shortestPath(adj, N, 0);
  for (int i = 0; i < N; i++) {
    cout << i << " " << res[i] << endl;
  }
  return 0;
}
