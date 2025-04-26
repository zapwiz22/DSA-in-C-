#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/** bellman ford algorithm for shortest path with negative weights as well
 * it also checks whether or not there is a negative cycle
 * time complexity: O(E*V) since two loops first with V times and second with E times
 * space complexity: O(V) for the resutl vector
 */
class Solution {
   public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
        vector<int> res(V, INT_MAX);
        res[S] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (auto &vec : edges) {
                int u = vec[0], v = vec[1], wt = vec[2];
                if (res[u] != INT_MAX && (res[u] + wt) < res[v]) {
                    res[v] = res[u] + wt;
                }
            }
        }
        for (auto &vec : edges) {
            int u = vec[0], v = vec[1], wt = vec[2];
            if (res[u] != INT_MAX && (res[u] + wt) < res[v]) {
                return vector<int>(V, -1);
            }
        }
        return res;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> edges(7, vector<int>(3));
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};

    Solution ans;
    vector<int> res = ans.bellman_ford(V, edges, 0);
    for (auto &val : res) {
        cout << val << " ";
    }
    cout << endl;

    cout << endl;

    // for negative weight cycle check
    int V1 = 3;
    vector<vector<int>> edges1(3, vector<int>(3));
    edges1[0] = {1, 2, -2};
    edges1[1] = {2, 3, -1};
    edges1[2] = {3, 1, 2};
    vector<int> res1 = ans.bellman_ford(V1, edges1, 0);
    for (auto &val : res1) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}