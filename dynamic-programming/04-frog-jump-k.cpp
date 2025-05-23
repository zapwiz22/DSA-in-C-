#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &height, int k) {
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
      }
    }
  }
  return dp[n - 1];
}

int main() {
  vector<int> height{30, 10, 60, 10, 60, 50};
  int n = height.size();
  int k = 2;
  cout << solve(n, height, k) << endl; // Print the result of the solve function
  return 0;
}
