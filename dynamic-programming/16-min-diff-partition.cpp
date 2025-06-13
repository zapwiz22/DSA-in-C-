#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/** new approach
 * meet in the middle
 * i.e., divide the array into 2 parts
 * and take sum from the first part
 * and remaining from the second one
 */
class Solution {
public:
  int minimumDifference(vector<int> &nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    int N = n / 2;
    vector<vector<int>> left(N + 1), right(N + 1);
    // finding all the sum of subsets using bitmasking
    for (int mask = 0; mask < (1 << N); mask++) {
      int cnt = 0, leftSum = 0, rightSum = 0;
      for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) {
          cnt++;
          leftSum += nums[i];
          rightSum += nums[N + i];
        }
      }
      left[cnt].push_back(leftSum);
      right[cnt].push_back(rightSum);
    }
    for (int i = 0; i <= N; i++) {
      sort(right[i].begin(), right[i].end());
    }
    int res = min(abs(total - 2 * left[N][0]), abs(total - 2 * right[N][0]));
    for (int i = 0; i < N; i++) {
      for (auto &sum1 : left[i]) {
        int rem = N - i;
        int target = total / 2 - sum1;
        auto it = lower_bound(right[rem].begin(), right[rem].end(), target);
        if (it != right[rem].end()) {
          int sum = sum1 + (*it);
          res = min(res, abs(total - 2 * sum));
        }
        if (it != right[rem].begin()) {
          it--;
          int sum = sum1 + (*it);
          res = min(res, abs(total - 2 * sum));
        }
      }
    }
    return res;
  }
};
