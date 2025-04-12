#include <iostream>
#include <vector>
using namespace std;

/* 26. Remove Duplicates from Sorted Array leetcode problem solution */
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int cnt = 1;
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                cnt++;
                j++;
                nums[j] = nums[i];
            }
            prev = nums[i];
        }
        return cnt;
    }
};

int main() {
    vector<int> vec = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5};
    Solution ans;
    cout << "the number of unique elements in vector is: " << ans.removeDuplicates(vec) << endl;
    for (auto val:vec) {
        cout << val << " ";
    }
    cout << endl;
}