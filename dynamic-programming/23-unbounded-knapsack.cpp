#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int func(int n, vector<int> &wt, vector<int> &val, int index, int W) {
  if (index == 0) {
    return (W / wt[0]) * val[0];
  }
  if (dp[index][W] != -1)
    return dp[index][W];
  int notTaken = func(n, wt, val, index - 1, W);
  int taken = INT_MIN;
  if (wt[index] <= W) {
    taken = val[index] + func(n, wt, val, index, W - wt[index]);
  }
  return dp[index][W] = max(taken, notTaken);
}

int main() {
  vector<int> wt = {2, 4, 6};    // Weight of items
  vector<int> val = {5, 11, 13}; // Value of items
  int W = 10;                    // Weight capacity of the knapsack
  int n = wt.size();             // Number of items

  // Call the function to calculate and output the maximum value the thief can
  // steal
  dp = vector<vector<int>>(n, vector<int>(W + 1, -1));
  cout << "The Maximum value of items the thief can steal is "
       << func(n, wt, val, n - 1, W);
  return 0; // Return 0 to indicate successful program execution
}
