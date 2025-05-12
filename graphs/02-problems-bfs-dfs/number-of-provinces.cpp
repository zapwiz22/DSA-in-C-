#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected[0].size();
        vector<bool> vis(n + 1, false);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(isConnected, vis, i);
            }
        }
        return cnt;
    }

   private:
    void dfs(vector<vector<int>> &isConn, vector<bool> &vis, int vertex) {
        int n = isConn[0].size();
        vis[vertex] = true;
        for (int i = 0; i < n; i++) {
            if (isConn[vertex - 1][i]) {
                if (!vis[i + 1]) {
                    dfs(isConn, vis, i + 1);
                }
            }
        }
    }
};