#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> size, parent;

   public:
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
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

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    } else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    } else
        cout << "Not same\n";
    return 0;
}