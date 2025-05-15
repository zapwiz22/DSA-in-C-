#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int low = 1, high = 1e6;
    int ans = 1e6;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int cnt = 0;
      for (auto &val : nums) {
        cnt += (val - mid + 1) / mid;
      }
      if (cnt <= threshold) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
};
