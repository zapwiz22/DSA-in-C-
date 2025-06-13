#include <iostream>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> dp;
  int func(int index, int target, vector<int> &coins) {
    if (index == 0) {
      if ((target % coins[0]) == 0)
        return target / coins[0];
      else
        return 1e6;
    }
    if (dp[index][target] != -1)
      return dp[index][target];
    int notTaken = func(index - 1, target, coins);
    int taken = 1e6;
    if (coins[index] <= target) {
      taken = 1 + func(index, target - coins[index], coins);
    }
    return dp[index][target] = min(taken, notTaken);
  }

public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    dp = vector<vector<int>>(n, vector<int>(amount + 1, -1));
    int cnt = func(n - 1, amount, coins);
    if (cnt < 1e6)
      return cnt;
    else
      return -1;
  }
};

/** another solution
* class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> vr(amount+1,amount+1);
        vr[0] = 0;
        for(int i = 1; i<amount+1; i++){
            for(auto &it: coins){
                if(i - it >= 0){
                    vr[i] = min(vr[i],1 + vr[i-it]);
                }
            }
        }
        if(vr[amount] == amount + 1) return -1;
        return vr[amount];
    }
};
*/
