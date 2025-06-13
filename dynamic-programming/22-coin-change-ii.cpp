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

/** important note
 * when using int or long long the any  value greater than the max value of that
 * type like INT_MAX or LLONG_MAX is undefined behaviour but unsigned int or
 * unsigned long long runs in loop so INT_MAX + 1 = 0 and so on for the long
 * long one too so this is undefined
 */
