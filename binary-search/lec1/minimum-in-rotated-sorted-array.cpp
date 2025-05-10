#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &vec) {
    int low = 0, high = vec.size() - 1, mid;
    int ans = INT_MAX;
    while (low <= high) {
        mid = low + (high - low) / 2;

        // more optimization if arr is already sorted then low one is the answer
        if (vec[low] <= vec[high]) {
            ans = min(ans, vec[low]);
            break;
        }

        if (vec[low] <= vec[mid]) {  // if left part sorted eliminate the left half
            ans = min(ans, vec[low]);
            low = mid + 1;
        } else {  // if right half sorted eliminate the right half
            ans = min(ans, vec[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << findMin(arr) << endl;
    return 0;
}