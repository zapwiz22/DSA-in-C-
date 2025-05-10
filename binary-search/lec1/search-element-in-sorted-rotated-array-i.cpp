#include <iostream>
#include <vector>
using namespace std;

int searchElement(vector<int> &vec, int target) {
    int low = 0, high = vec.size() - 1, mid;
    int ans = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (vec[mid] == target) return mid;
        if (vec[low] <= vec[mid]) {
            if (vec[low] <= target and target <= vec[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (vec[mid] <= target and target <= vec[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << searchElement(arr, 1) << endl;
    return 0;
}