#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        int ans = INT_MAX;
        ;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long int cnt = 0;
            for (auto& val : piles) {
                cnt += (val + mid - 1) / mid;
            }
            if (cnt <= h) {
                ans = min(mid, ans);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
