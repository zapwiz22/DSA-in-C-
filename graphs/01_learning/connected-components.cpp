#include <iostream>
#include <vector>
using namespace std;

// code for finding the number of connected components in a graph
class Solution {
   public:
    int findNumberOfComponent(int E, int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        for (auto &vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        vector<bool> vis(V, false);
        int res = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                res++;
                dfs(graph, vis, i);
            }
        }
        return res;
    }

   private:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int vertex) {
        vis[vertex] = true;
        for (auto &neigh : graph[vertex]) {
            if (!vis[neigh]) {
                dfs(graph, vis, neigh);
            }
        }
    }
};

int main() {
    Solution ans;
    int E = 4, V = 7;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
    cout << ans.findNumberOfComponent(E, V, edges) << endl;
    int E1 = 2, V1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
    cout << ans.findNumberOfComponent(E1, V1, edges1) << endl;
    return 0;
}