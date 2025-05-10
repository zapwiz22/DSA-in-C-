#include <iostream>
#include <vector>
using namespace std;

int lastOccurrence(vector<int> &vec, int target) {
    int ans = -1;
    int low = 0, high = vec.size() - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (vec[mid] == target) {
            ans = mid;
            low = mid + 1;
        } else if (vec[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector nums = {3, 4, 13, 13, 13, 20, 40};
    cout << lastOccurrence(nums, 13) << endl;
    vector nums2 = {3, 4, 13, 13, 13, 20, 40};
    cout << lastOccurrence(nums2, 60) << endl;
    return 0;
}