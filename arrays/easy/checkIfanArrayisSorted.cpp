#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* is_sorted(beginning,end) returns true if sorted else false */

/* solution for the leetcode problem 1752. Check if Array Is Sorted and Rotated */
class Solution {
   public:
    bool check(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) return true;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) count++;
        }
        if (count > 1) return false;
        if (count <= 1 and nums[nums.size() - 1] <= nums[0])
            return true;
        else
            return false;
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Solution ans;
    vector<int> vec2 = {4,5,1,2,3};
    vector<int> vec3 = {4,2,6,1};
    cout << "is vector sorted before being rotated 0 or more times: " << ans.check(vec) << endl; /* 1 for true and 0 for false */
    cout << "is vector sorted before being rotated 0 or more times: " << ans.check(vec2) << endl; /* 1 for true and 0 for false */
    cout << "is vector sorted before being rotated 0 or more times: " << ans.check(vec3) << endl; /* 1 for true and 0 for false */
}