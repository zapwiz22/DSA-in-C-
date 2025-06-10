#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int mxemumChocolates(int n, int m, vector<vector<int>> &matrix) {
  vector<vector<vector<int>>> dp(
      n,
      vector<vector<int>>(
          m,
          vector<int>(
              m, 0))); // dp[k][i][j] represents the number of chocolates while
                       // first friend is at (k,i) and second is at (k,j)

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = matrix[n - 1][j1];
      else
        dp[n - 1][j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {
        int mxe = INT_MIN;
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            int ans;
            if (j1 == j2)
              ans = matrix[i][j1];
            else
              ans = matrix[i][j1] + matrix[i][j2];
            // Check if the move is valid (within the grid boundaries)
            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
              ans += -1e9; // A very large negative value to represent an
                           // invalid move
            else
              ans += dp[i + 1][j1 + di]
                       [j2 + dj]; // Include the DP result from the next row

            mxe = max(ans, mxe); // Update the mxemum result
          }
        }
        dp[i][j1][j2] = mxe;
      }
    }
  }
  return dp[0][0][m - 1];
}

int main() {
  // Define the grid as a 2D vector
  vector<vector<int>> matrix{
      {2, 3, 1, 2},
      {3, 4, 2, 2},
      {5, 6, 3, 5},
  };

  int n = matrix.size();    // Number of rows
  int m = matrix[0].size(); // Number of columns

  // Call the mxemumChocolates function and print the result
  cout << mxemumChocolates(n, m, matrix);

  return 0;
}
