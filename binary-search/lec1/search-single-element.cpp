#include <iostream>
#include <vector>
using namespace std;

int singleElement(vector<int> &vec) {
    if (vec.size() == 1) return vec[0];
    if (vec[0] != vec[1])
        return vec[0];
    else if (vec[vec.size() - 1] != vec[vec.size() - 2])
        return vec[vec.size() - 1];
    int low = 0, high = vec.size() - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (vec[mid] != vec[mid + 1] and vec[mid] != vec[mid - 1]) {
            return vec[mid];
        } else if (vec[mid] == vec[mid + 1]) {
            if ((mid - low + 2) & 1) {
                high = mid - 1;
            } else {
                low = mid + 2;
            }
        } else {
            if ((mid - low + 1) & 1) {
                high = mid - 2;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << singleElement(arr) << endl;
    return 0;
}