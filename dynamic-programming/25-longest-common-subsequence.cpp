#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> dp;
  int func(int idx1, int idx2, string &text1, string &text2) {
    if (idx1 < 0 || idx2 < 0)
      return 0;
    if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    int taken = 0;
    if (text1[idx1] == text2[idx2])
      taken = 1 + func(idx1 - 1, idx2 - 1, text1, text2);
    int notTaken = max(func(idx1, idx2 - 1, text1, text2),
                       func(idx1 - 1, idx2, text1, text2));
    return dp[idx1][idx2] = max(taken, notTaken);
  }

public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    // dp = vector<vector<int>>(n, vector<int>(m, -1));
    // return func(n - 1, m - 1, text1, text2);

    // another approach bottom up
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp2[i][j] = 1 + dp2[i - 1][j - 1];
        } else {
          dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
        }
      }
    }
    return dp2[n][m];
  }
};
