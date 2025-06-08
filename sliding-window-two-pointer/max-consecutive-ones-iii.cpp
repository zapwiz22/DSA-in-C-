#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int ans = 0, zeros = 0, ones = 0;
    int left = 0, right = 0, n = nums.size();
    while (right < n) {
      if (nums[right])
        ones++;
      else
        zeros++;
      if (zeros > k) {
        while (zeros > k and left <= right) {
          if (nums[left])
            ones--;
          else
            zeros--;
          left++;
        }
      }
      ans = max(ans, zeros + ones);
      right++;
    }
    return ans;
  }
};
