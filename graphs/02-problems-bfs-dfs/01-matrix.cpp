#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> dirns = {0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0)
          q.emplace(i, j);
        else
          mat[i][j] = -1;
      }
    }
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nr = r + dirns[i], nc = c + dirns[i + 1];
        if (nr < 0 or nc < 0 or nc >= n or nr >= m or mat[nr][nc] != -1)
          continue;
        mat[nr][nc] = mat[r][c] + 1;
        q.emplace(nr, nc);
      }
    }
    return mat;
  }
};
