#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    int first = 0, second = nums[0];
    for (int i = 1; i < n; i++) {
      int third = max(nums[i] + first, second);
      first = second;
      second = third;
    }
    return second;
  }
};
