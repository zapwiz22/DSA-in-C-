#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int low = 0, high = 0;
        for (auto &val : bloomDay) high = max(high, val);
        int ans = -1;
        if (bloomDay.size() < (1ll * m * k)) return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            int curr = 0;
            for (auto &val : bloomDay) {
                if (val <= mid) {
                    curr++;
                } else {
                    curr = 0;
                }
                if (curr == k) {
                    cnt++;
                    curr = 0;
                }
                if (cnt >= m) {
                    ans = mid;
                    high = mid - 1;
                    break;
                }
            }
            if (cnt < m) {
                low = mid + 1;
            }
        }
        return ans;
    }
};