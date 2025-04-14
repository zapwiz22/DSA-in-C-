#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* 1. Two Sum leetcode problem solution */
/* O (nlogn) time complexity submission */
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<pair<int,int>> pr;
        for (int i=0;i<nums.size();i++) {
            pr.push_back({nums[i],i});
        }
        sort(pr.begin(),pr.end());
        while (i < j) {
            if ((pr[i].first + pr[j].first) < target) {
                i++;
            } else if ((pr[i].first + pr[j].first) > target) {
                j--;
            } else {
                return {pr[i].second, pr[j].second};
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> vec = {3,2,4};
    Solution ans;
    vector<int> sol = ans.twoSum(vec,6);
    cout << sol[0] << " " << sol[1] << endl;
    return 0;
}