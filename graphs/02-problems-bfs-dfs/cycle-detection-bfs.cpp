#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    bool detectCycle(int V, vector<vector<int>> &adjList) {
        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (check(adjList, vis, i)) return true;
            }
        }
        return false;
    }

   private:
    bool check(vector<vector<int>> &adjList, vector<bool> &vis, int vertex) {
        vis[vertex] = true;
        queue<pair<int, int>> q;
        q.push({vertex, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto &adjNode : adjList[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                } else if (parent != adjNode) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // V = 4, E = 2
    vector<vector<int>> adj = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.detectCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}