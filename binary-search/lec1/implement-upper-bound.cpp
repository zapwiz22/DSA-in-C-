#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int> &nums, int num) {
    int left = 0, right = nums.size(), mid;
    int ans = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] <= num) {
            left = mid + 1;
        } else {
            ans = nums[mid];
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector nums = {1, 2, 2, 3};
    cout << upperBound(nums, 2) << endl;
    vector nums2 = {3, 5, 8, 9, 15, 19};
    cout << upperBound(nums2, 9) << endl;
    return 0;
}