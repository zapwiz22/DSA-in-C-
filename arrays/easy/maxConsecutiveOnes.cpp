#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]==0) curr=0;
            curr+=nums[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution ans;
    cout << ans.findMaxConsecutiveOnes(nums) << endl;
}