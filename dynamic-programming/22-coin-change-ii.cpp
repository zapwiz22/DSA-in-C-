#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] += dp[i - coin];
        if (dp[i] > INT_MAX) {
          dp[i] = INT_MAX;
        }
      }
    }
    return dp[amount];
  }
};
