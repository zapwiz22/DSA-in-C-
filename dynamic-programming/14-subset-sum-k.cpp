#include <iostream>
#include <vector>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  // base cases if no element selected then target sum 0 is true if first
  // element selected and is less than target sum then it is true
  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }
  if (arr[0] <= k) {
    dp[0][arr[0]] = true;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      bool notTaken = dp[i - 1][k];
      bool taken = false;
      if (arr[i] <= k) {
        taken = dp[i - 1][k - arr[i]];
      }
      dp[i][j] = taken || notTaken;
    }
  }
  return dp[n - 1][k];
}

vector<vector<int>> dp;
bool func(int index, int target, vector<int> &arr) {
  if (target == 0)
    return true;
  if (index == 0) {
    if (arr[0] == target)
      return true;
    else
      return false;
  }
  if (dp[index][target] != -1)
    return dp[index][target];
  bool notTaken = func(index - 1, target, arr);
  bool taken = false;
  if (arr[index] <= target) {
    taken = func(index - 1, target - arr[index], arr);
  }
  return dp[index][target] = taken || notTaken;
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  int k = 4;
  int n = arr.size();

  // Call the subsetSumToK function and print the result
  if (subsetSumToK(n, k, arr))
    cout << "Subset with the given target found";
  else
    cout << "Subset with the given target not found";
  cout << endl;
  dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
  cout << func(n - 1, k, arr) << endl;
  return 0;
}
