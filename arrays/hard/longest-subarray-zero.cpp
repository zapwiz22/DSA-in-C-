#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// T.C. :- O(n^2)  S.C. :- O(1)
// int longestSubarrayZero(vector<int> &nums) {
//     int n = nums.size();
//     int res = 0;
//     for (int i = 0; i < n; i++) {
//         int sum = nums[i];
//         if (sum == 0) res = max(res, 1);
//         for (int j = i + 1; j < n; j++) {
//             sum += nums[j];
//             if (sum == 0) res = max(res, j - i + 1);
//         }
//     }
//     return res;
// }

// T.C. :- O(n)  S.C. :- O(n)
int longestSubarrayZero(vector<int> &vec) {
    int n = vec.size();
    unordered_map<int, int> mp;
    int res = 0;
    int sum = 0;
    mp[0] = -1; // for the sum equaling zero till the current element traversed
    for (int i = 0; i < n; i++) {
        sum += vec[i];
        if (mp.find(sum) != mp.end()) {
            res = max(res, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    return res;
}

int main() {
    vector nums = {9, -3, 3, -1, 6, -5};
    cout << longestSubarrayZero(nums) << endl;
    vector nums2 = {6, -2, 2, -8, 1, 7, 4, -10};
    cout << longestSubarrayZero(nums2) << endl;
    return 0;
}