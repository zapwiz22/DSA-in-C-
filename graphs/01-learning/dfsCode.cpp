#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/** dfs code */
void dfs(vector<vector<int>> &graph, vector<bool> &vis, int vertex) {
    vis[vertex] = true;
    cout << vertex << " ";
    for (auto &neigh : graph[vertex]) {
        if (!vis[neigh]) {
            dfs(graph, vis, neigh);
        }
    }
}

int main() {
    int E = 4, V = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> graph(V);
    for (auto &vec : edges) {
        graph[vec[0]].push_back(vec[1]);
        graph[vec[1]].push_back(vec[0]);
    }
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(graph, vis, i);
        }
    }
    return 0;
}