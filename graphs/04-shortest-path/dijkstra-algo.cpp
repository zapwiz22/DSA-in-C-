#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/** dijktra's algorithm to find the shortest distance to a node from the source node
 * time complexity: O(E logV) since all edges are traversed and push and pop is of logV time (V since while using set only at max V number of pairs will be there in the set)
 * space complexity: O(E + V) since priority queue stores the number of edges nodes are stored in the res vector
 * only used if no negative weights in this and this is a greedy approach
 */
class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> res(V, INT_MAX);
        res[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, S);
        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &vec : adj[node]) {
                int neigh = vec[0];
                int dist = vec[1];
                if ((currDist + dist) < res[neigh]) {
                    res[neigh] = currDist + dist;
                    pq.emplace(res[neigh], neigh);
                }
            }
        }
        return res;
    }
};

int main() {
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution ans;
    vector<int> res = ans.dijkstra(V, adj, S);
    for (auto &val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}