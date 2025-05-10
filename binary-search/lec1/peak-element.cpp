#include <iostream>
#include <vector>
using namespace std;

int peakElement (vector<int> &vec) {
    if (vec[0]>=vec[1] || vec.size()==1) return vec[0];
    if (vec[vec.size()-1]>=vec[vec.size()-2]) return vec[vec.size()-1];
    int low = 0, high = vec.size()-1, mid;
    while (low<=high) {
        mid = low + (high-low)/2;
        if (vec[mid]>=vec[mid+1] and vec[mid]>=vec[mid-1]) return vec[mid];
        else if (vec[mid]>=vec[mid-1]) {
            low = mid + 1;
        } else if (vec[mid]>=vec[mid+1]) {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout << peakElement(arr) << endl;
    return 0;
}