#include <iostream>
#include <vector>
using namespace std;

/* 2149. Rearrange Array Elements by Sign leetcode problem solution */

/* brute force solution */
// class Solution {
//    public:
//     vector<int> rearrangeArray(vector<int> &nums) {
//         vector<int> pos, neg;
//         for (auto &val : nums) {
//             if (val > 0)
//                 pos.push_back(val);
//             else
//                 neg.push_back(val);
//         }
//         for (int i = 0; i < (nums.size() / 2); i++) {
//             nums[2 * i] = pos[i];
//             nums[2 * i + 1] = neg[i];
//         }
//         return nums;
//     }
// };

/* optimized solution in one traversal */
class Solution {
   public:
    vector<int> rearrangeArray(vector<int> &nums) {
        int posIndex = 0, negIndex = 1;
        vector<int> result(nums.size());
        for (auto &val : nums) {
            if (val > 0) {
                result[posIndex] = val;
                posIndex += 2;
            } else {
                result[negIndex] = val;
                negIndex += 2;
            }
        }
        return result;
    }
};

int main() {
    vector<int> vec = {3, 1, -2, -5, 2, -4};
    Solution ans;
    vector<int> result = ans.rearrangeArray(vec);
    for (auto &val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}