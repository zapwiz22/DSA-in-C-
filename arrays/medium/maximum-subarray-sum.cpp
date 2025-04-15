#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/* 53. Maximum Subarray leetcode problem solution using Kadane's algorithm */
/* we find the max sum and if the sum becomes less than zero then we again reinitialize sum to 0 because it is better not to choose a negative sum as the beginning for the next element*/
/* O(n) */
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;
        for (auto& val : nums) {
            sum += val;
            if (sum > res) res = sum;
            if (sum < 0) {
                sum = 0;
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution ans;
    cout << ans.maxSubArray(vec) << endl;
    return 0;
}