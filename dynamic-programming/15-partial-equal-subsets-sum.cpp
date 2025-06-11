#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  bool func(int index, int curr, int total, vector<int> &nums,
            vector<vector<int>> &dp) {
    if (index == 0) {
      if (2 * (curr + nums[index]) == total)
        return true;
      else if (2 * (curr) == total)
        return true;
      else
        return false;
    }
    if (dp[index][curr] != -1)
      return dp[index][curr];
    bool notTaken = func(index - 1, curr, total, nums, dp);
    bool taken = func(index - 1, curr + nums[index], total, nums, dp);
    return dp[index][curr] = taken || notTaken;
  }

public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total & 1)
      return false;
    vector<vector<int>> dp(n, vector<int>(total + 1, -1));
    return func(n - 1, 0, total, nums, dp);
  }
};
