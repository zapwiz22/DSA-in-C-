#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int timesRotated(vector<int> &vec) {
    int low = 0, high = vec.size() - 1, mid;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (vec[low] <= vec[high]) {
            if (vec[low] < ans) {
                ans = vec[low];
                index = low;
            }
            break;
        }
        if (vec[low] <= vec[mid]) {
            if (vec[low] < ans) {
                ans = vec[low];
                index = low;
            }
            low = mid + 1;
        } else {
            if (vec[mid] < ans) {
                ans = vec[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << timesRotated(arr) << endl;
    return 0;
}