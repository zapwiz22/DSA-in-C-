#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> dp;
  int func(int index, int target, vector<int> &arr) {
    if (index == 0) {
      if (target == 0 and arr[0] == 0)
        return 2;
      if (arr[0] == target || target == 0)
        return 1;
      return 0;
    }
    if (dp[index][target] != -1)
      return dp[index][target];
    int notTaken = func(index - 1, target, arr);
    int taken = 0;
    if (arr[index] <= target) {
      taken = func(index - 1, target - arr[index], arr);
    }
    return dp[index][target] = taken + notTaken;
  }

public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (target > total)
      return 0;
    if ((total - target) & 1)
      return 0;
    int final = (total - target) / 2;
    dp = vector<vector<int>>(n, vector<int>(final + 1, -1));
    return func(n - 1, final, nums);
  }
};
