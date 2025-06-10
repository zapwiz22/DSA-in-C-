#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          obstacleGrid[i][j] = 0;
          continue;
        }
        if (i == 0 and j == 0) {
          obstacleGrid[i][j] = 1;
          continue;
        }
        ll up = 0, left = 0;
        if (i > 0)
          up = obstacleGrid[i - 1][j];
        if (j > 0)
          left = obstacleGrid[i][j - 1];
        obstacleGrid[i][j] = up + left;
      }
    }
    return obstacleGrid[m - 1][n - 1];
  }
};
