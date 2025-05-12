#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/** prim's algorithm to find the minimum spanning tree
 * time complexity: O(E*logE) + O(E*logE) ~ O(E*logE) first OlogE for traversing the priority queue and popping and second one for traversing the nodes and emplacing
 * space complexity: O(E+V) E for priority queue and V for visited vector
 * for storing the mst keep a mst vector which stores the parent of each node
 */
class Solution {
   public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        int sum = 0;
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (vis[node]) continue;
            sum += wt;
            // mstArray[node] = parent;
            vis[node] = true;
            for (auto &vec : adj[node]) {
                int adjNode = vec[0];
                int edgeWt = vec[1];
                if (!vis[adjNode]) {
                    pq.emplace(edgeWt, adjNode);
                    // for getting mstArray instead do pq.emplace(edgeWt, adjNode, node); // node here is parent;
                }
            }
        }
        return sum;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution ans;
    cout << ans.spanningTree(V, adj) << endl;
    return 0;
}