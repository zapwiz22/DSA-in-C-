#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int up = INT_MAX, left = INT_MAX;
        if (i == 0 and j == 0)
          continue;
        if (i > 0)
          up = grid[i - 1][j];
        if (j > 0)
          left = grid[i][j - 1];
        grid[i][j] += min(up, left);
      }
    }
    return grid[m - 1][n - 1];
  }
};
