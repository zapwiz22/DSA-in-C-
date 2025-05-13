#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool detectCycle(int V, vector<vector<int>> &adjList) {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (check(i, -1, adjList, vis)) return true;
            }
        }
        return false;
    }

   private:
    bool check(int src, int parent, vector<vector<int>> &adjList, vector<bool> &vis) {
        vis[src] = true;
        for (auto &adjNode : adjList[src]) {
            if (!vis[adjNode]) {
                return check(adjNode, src, adjList, vis);
            } else {
                if (adjNode != parent) {
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