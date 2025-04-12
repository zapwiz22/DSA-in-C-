#include <iostream>
#include <vector>
using namespace std;

/* O(n*n)
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - cnt; i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < nums.size() - cnt; j++) {
                    swap(nums[j], nums[j - 1]);
                }
                cnt++;
                i--;
            }
        }
    }
};
*/

// O(n) time complexity
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }
        if (j == -1) return;
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    vector<int> vec = {0, 0, 1};
    Solution ans;
    ans.moveZeroes(vec);
    for (auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}