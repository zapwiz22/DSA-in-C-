#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int uParentU = findUPar(u);
        int uParentV = findUPar(v);
        if (rank[uParentU] < rank[uParentV])
            parent[uParentU] = uParentV;
        else if (rank[uParentU] > rank[uParentV])
            parent[uParentV] = uParentU;
        else {
            parent[uParentV] = uParentU;
            rank[uParentU]++;
        }
    }
};

int main() {
}