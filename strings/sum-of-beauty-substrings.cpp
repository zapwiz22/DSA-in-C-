#include <climits>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
   public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26, 0);
            int mxe = INT_MIN;
            for (int j = i; j < s.size(); j++) {
                cnt[s[j] - 'a']++;
                mxe = max(mxe, cnt[s[j] - 'a']);
                int mne = INT_MAX;
                for (auto &val : cnt) {
                    if (val != 0) mne = min(mne, val);
                }
                ans += mxe - mne;
            }
        }
        return ans;
    }
};

int main() {
    cout << (new Solution)->beautySum("aabcb") << endl;  // answer is 5
    return 0;
}