#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < triangle[i].size(); j++) {
        int first = INT_MAX, second = INT_MAX;
        if (j != triangle[i].size() - 1)
          first = triangle[i][j] + triangle[i - 1][j];
        if (j)
          second = triangle[i][j] + triangle[i - 1][j - 1];
        triangle[i][j] = min(first, second);
      }
    }
    int mne = INT_MAX;
    for (int i = 0; i < triangle[n - 1].size(); i++) {
      mne = min(mne, triangle[n - 1][i]);
    }
    return mne;
  }
};
