#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int func(int index, int target, vector<int> &arr) {
  if (index == 0) {
    if (target == 0 and arr[0] == target)
      return 2;
    if (target == 0 || target == arr[0])
      return 1;
    return 0;
  }
  if (dp[index][target] != -1)
    return dp[index][target];
  int notTaken = func(index - 1, target, arr);
  int taken = 0;
  if (arr[index] < target) {
    taken = func(index - 1, target - arr[index], arr);
  }
  return dp[index][target] = taken + notTaken;
}

int findWays(vector<int> &arr, int D) {
  int total = accumulate(arr.begin(), arr.end(), 0);
  int n = arr.size();
  if (total - D < 0)
    return 0;
  if ((total - D) & 1)
    return 0;
  int target = (total - D) / 2;
  dp = vector<vector<int>>(n, vector<int>(target + 1, -1));
  return func(n - 1, target, arr);
}

int main() {

  vector<int> arr = {5, 2, 6, 4};
  int d = 3;

  cout << "The number of subsets found are " << findWays(arr, d);
}
