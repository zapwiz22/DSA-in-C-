#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/** to detect cycle in a directed graph
 * do topological sorting
 * if the number of elements in the topological sorting != total elements
 * then there is a cycle
 */
class Solution {
public:
  bool isCyclic(int V, vector<vector<int>> &adjList) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
      for (auto &it : adjList[i]) {
        indegree[it]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      cnt++;
      for (auto adjNode : adjList[node]) {
        indegree[adjNode]--;
        if (indegree[adjNode] == 0)
          q.push(adjNode);
      }
    }
    if (cnt == V)
      return false;
    return true;
  }
};

int main() {
  vector<vector<int>> adjList = {{}, {2}, {3}, {4, 5}, {2}, {}};
  Solution obj;
  cout << obj.isCyclic(6, adjList) << endl;
  return 0;
}
