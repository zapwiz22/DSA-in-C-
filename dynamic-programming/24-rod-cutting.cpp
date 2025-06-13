#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int func(int index, int N, vector<int> &prices) {
  if (index == prices.size() - 1)
    return prices[N - 1];
  if (dp[index][N] != -1)
    return dp[index][N];
  // cut here
  int cut = prices[N - 1] + func(index + 1, 1, prices);
  // don't cut and include
  int uncut = func(index + 1, N + 1, prices);
  return dp[index][N] = max(cut, uncut);
}

int main() {
  int N = 5;
  vector<int> prices = {2, 5, 7, 8, 10};
  int n = prices.size();

  dp = vector<vector<int>>(n, vector<int>(N + 1, -1));
  cout << "Maximum price after cutting is: " << func(0, 1, prices) << endl;

  // second way (i am thinking as bottom up approach)
  vector<int> dp2(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i - j >= 0) {
        dp2[i] = max(dp2[i], prices[j - 1] + dp2[i - j]);
      }
    }
  }
  cout << "Maximum price after cutting is(using second approach): " << dp2[N]
       << endl;
  return 0;
}
