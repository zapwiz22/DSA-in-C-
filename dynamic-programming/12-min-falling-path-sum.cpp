#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int first = INT_MAX, second = INT_MAX, third = INT_MAX;
        first = matrix[i - 1][j];
        if (j != 0)
          second = matrix[i - 1][j - 1];
        if (j != n - 1)
          third = matrix[i - 1][j + 1];
        matrix[i][j] += min({first, second, third});
      }
    }
    return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
  }
};
