#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int splitArray(vector<int> &nums, int k) {
    int low = *max_element(nums.begin(), nums.end()),
        high = accumulate(nums.begin(), nums.end(), 0ll);
    int ans;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int cnt = 0;
      int curr = 0;
      int res = -1;
      for (auto &val : nums) {
        res = max(res, curr);
        curr += val;
        if (curr > mid) {
          cnt++;
          curr = val;
        }
      }
      res = max(res, curr);
      if (curr)
        cnt++;
      if (cnt <= k) {
        ans = res;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
};
