#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int low = 0, high = 0;
    for (auto &val : weights) {
      low = max(low, val);
      high += val;
    }
    int ans;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int cnt = 0;
      int curr = 0;
      for (auto &val : weights) {
        curr += val;
        if (curr > mid) {
          cnt++;
          curr = val;
        }
      }
      if (curr)
        cnt++;
      if (cnt <= days) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
};
