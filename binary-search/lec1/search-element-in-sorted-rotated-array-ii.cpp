#include <iostream>
#include <vector>
using namespace std;

/** only difference is that this vector can contain duplicates too
 * to deal the edge case in this where the low and high value are equal to the mid and not the target
 * we simply reduce the search space by those two postitions
 * T.C. :- O(logn) but worst is O(n/2) if (all elements are equal and not the target)
 */
int searchElement(vector<int> &vec, int target) {
    int low = 0, high = vec.size() - 1, mid;
    int ans = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (vec[mid] == target) return mid;

        // edge case
        if (vec[mid] == vec[low] and vec[low] == vec[high]) {
            high--, low++;
            continue;
        }

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
    vector<int> arr = {7, 8, 1, 1, 2, 3, 3, 3, 4, 5, 5, 6};
    cout << searchElement(arr, 3) << endl;
    return 0;
}