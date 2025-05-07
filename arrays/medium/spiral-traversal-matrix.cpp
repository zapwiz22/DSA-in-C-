#include <iostream>
#include <vector>
using namespace std;

void spiralTraversal(vector<vector<int>> &matrix) {
    vector<pair<int, int>> dirns = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int x = 0, y = 0;
    int currDirn = 0;
    int dx = dirns[currDirn].first, dy = dirns[currDirn].second;
    for (int i = 0; i < n * m; i++) {
        cout << matrix[x][y] << " ";
        vis[x][y] = true;
        int newx = x + dx, newy = y + dy;
        if (newx >= n or newx < 0 or newy >= m or newy < 0 or vis[newx][newy]) {
            currDirn = (currDirn + 1) % 4;
            dx = dirns[currDirn].first, dy = dirns[currDirn].second;
            x = x + dx, y = y + dy;
        } else {
            x = newx, y = newy;
        }
    }
}

int main() {
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};
    spiralTraversal(mat);
}