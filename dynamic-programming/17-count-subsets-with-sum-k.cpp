#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int func(int index, int target, vector<int> &arr) {
  if (target == 0)
    return 1;
  if (index == 0) {
    return arr[0] == target;
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

int findWays(vector<int> &arr, int k) {
  int n = arr.size();
  dp = vector<vector<int>>(n, vector<int>(k + 1, 0));
  return func(n - 1, k, arr);
}

int main() {
  vector<int> arr = {1, 2, 2, 3};
  int k = 3;

  cout << "The number of subsets found are " << findWays(arr, k);

  return 0;
}
