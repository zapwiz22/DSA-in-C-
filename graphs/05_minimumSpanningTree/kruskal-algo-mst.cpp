#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> size, parent;

   public:
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ul_par_u = findUPar(u);
        int ul_par_v = findUPar(v);
        if (size[ul_par_u] < size[ul_par_v]) {
            parent[ul_par_u] = ul_par_v;
            size[ul_par_v] += size[ul_par_u];
        } else {
            parent[ul_par_v] = ul_par_u;
            size[ul_par_u] += size[ul_par_v];
        }
    }
};

/** kruskal's algorithm for finding the minimum spanning tree
 * time complexity: O(V+E) + O(E logE) + O(E*4α*2)
 * space complexity: 2*O(V) + O(E)
 */
class Solution {
   public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto &vec : adj[i]) {
                edges.push_back({vec[1], {i, vec[0]}});
            }
        }
        int mst = 0;
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        for (auto &it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mst += wt;
                ds.unionBySize(u, v);
            }
        }
        return mst;
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

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}