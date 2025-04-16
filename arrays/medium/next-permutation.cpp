#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* 31. Next Permutation leetcode problem solution */
/* directly using the built in function in algorithm to find the next permutation */
class Solution {
   public:
    void nextPermutation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
        return;
    }

    /* method of finding the next-permutation without using the function */
    /* better say the implementation of the function next_permutation() */
    void anotherMethodNextPermutation(vector<int> &nums) {
        int n = nums.size();
        int ind = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
        return;
    }
};

int main() {
    vector<int> vec = {1, 2, 3};
    Solution ans;
    ans.nextPermutation(vec);
    for (auto &val : vec) {
        cout << val << " ";
    }
    cout << endl;
    ans.anotherMethodNextPermutation(vec);
    for (auto &val : vec) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}