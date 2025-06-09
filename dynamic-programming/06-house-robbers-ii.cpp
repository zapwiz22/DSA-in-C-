#include <iostream>
#include <vector>
using namespace std;

/** solution
 * find two answers
 * first not including the last number
 * second not including the first number
 * as atmost 1 of them can be selected
 * the max of both will be the answer
 */
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    int first = 0, second = nums[0];
    for (int i = 1; i < n - 1; i++) {
      int third = max(first + nums[i], second);
      first = second;
      second = third;
    }
    int ans1 = second;
    if (n == 1)
      return second;
    first = 0, second = nums[1];
    for (int i = 2; i < n; i++) {
      int third = max(first + nums[i], second);
      first = second;
      second = third;
    }
    int ans2 = second;
    return max(ans1, ans2);
  }
};

int main() {}
