#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* 121. Best Time to Buy and Sell Stock leetcode problem solution */
/* simple just checking and comparing if the value greater than a minimum found then store max result else change minimum */
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int mne = prices[0];
        for (auto& val : prices) {
            if (val > mne) {
                res = max(res, val - mne);
            } else {
                mne = val;
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec = {7, 6, 4, 3, 1};
    vector<int> vec2 = {2, 1, 4};
    Solution ans;
    cout << ans.maxProfit(vec) << endl;
    cout << ans.maxProfit(vec2) << endl;
    return 0;
}
