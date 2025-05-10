#include <iostream>
#include <vector>
using namespace std;

int binarySearchItr(vector<int> &vec, int target) {
    int left = 0, right = vec.size() - 1;
    int mid = left + (right - left) / 2;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (vec[mid] > target) {
            right = mid - 1;
        } else if (vec[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binarySearchRec(vector<int> &vec, int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (vec[mid] < target)
        return binarySearchRec(vec, mid + 1, high, target);
    else if (vec[mid] > target)
        return binarySearchRec(vec, low, mid - 1, target);
    else
        return mid;
}

int main() {
    vector nums = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    cout << binarySearchItr(nums, target) << endl;
    cout << binarySearchRec(nums, 0, nums.size() - 1, target) << endl;
    return 0;
}