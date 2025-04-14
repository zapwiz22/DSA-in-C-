#include <iostream>
#include <vector>
using namespace std;

/* 75. Sort Colors leetcode problem solution */
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        /* direct solution is to use the sort function in the <algorithm> library */
        // sort(nums.begin(),nums.end());

        /* second method "Dutch Flag Algorithm"*/
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++, mid++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else {
                mid++;
            }
        }
    }
};

int main() {
    vector<int> vec = {2, 0, 2, 1, 1, 0};
    Solution ans;
    ans.sortColors(vec);
    for (auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}