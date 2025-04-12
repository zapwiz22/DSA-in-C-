#include <iostream>
#include <vector>
using namespace std;

/* 189. Rotate Array leetcode solution in O(n) space complexity and O(n) time complexity*/
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % (nums.size());
        vector<int> ans;
        for (int i = nums.size() - k; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size() - k; i++) {
            ans.push_back(nums[i]);
        }
        nums = ans;
        return;
    }
};

/* space complexity can be reduced by following the below strategy */
/* 1. reverse the first n-k elements */
/* 2. reverse the next k elements */
/* 3. reverse the full vector/array */
/* this is O(n) time complexity and O(1) space complexity */

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Solution ans;
    ans.rotate(vec, 3);
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}