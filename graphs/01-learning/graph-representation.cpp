#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int M;  // edges
    cin >> M;

    // adjacent matrix representation of graph but this is space consuming
    int adjMatrix[N][N];
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // adjacency list representation of graph
    vector<vector<int>> adjList(N);  // or --> vector<int> adjList[N]
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}