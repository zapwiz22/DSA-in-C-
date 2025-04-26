#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/** bfs traversal
 * pushing INT_MIN to indicate different levels else no need
 */
void bfs(vector<vector<int>> &graph, vector<bool> &vis, int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    q.push(INT_MIN);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == INT_MIN) {
            if (!q.empty()) {
                q.push(INT_MIN);
            }
            cout << endl;
            continue;
        }
        cout << curr << " ";
        for (auto &neigh : graph[curr]) {
            if (!vis[neigh]) {
                q.push(neigh);
                vis[neigh] = true;
            }
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
            bfs(graph, vis, i);
        }
    }
    return 0;
}