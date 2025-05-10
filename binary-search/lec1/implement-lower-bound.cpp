#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &nums, int num) {
    int mid;
    int left = 0, right = nums.size();
    int ans = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        // if (nums[mid] < num) {
        //     left = mid + 1;
        // } else if (nums[mid] > num) {
        //     right = mid - 1;
        // } else {
        //     left = mid;
        // }

        /* better method for the above code */
        if (nums[mid] >= num) {
            ans = nums[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // return nums[left];
    return ans;
}

int main() {
    vector nums = {3, 5, 8, 15, 19};
    cout << lowerBound(nums, 9) << endl;
    vector nums2 = {1, 2, 2, 3};
    cout << lowerBound(nums2, 2) << endl;
    return 0;
}
