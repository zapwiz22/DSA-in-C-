#include <iostream>
#include <vector>
using namespace std;

/* 169. Majority Element leetcode problem solution */
/* solution using moore's algorithm */
/* O (n) */
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, res;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                cnt = 1;
                res = nums[i];
            } else if (nums[i] == res)
                cnt++;
            else
                cnt--;
        }
        return res;
    }
};

int main() {
    vector<int> vec = {10, 9, 9, 9, 10};
    Solution ans;
    cout << ans.majorityElement(vec) << endl;
    return 0;
}