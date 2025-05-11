#include <cmath>
#include <iostream>
using namespace std;

int floorSqrtBuiltIn(int n) {
    return sqrt(n);
}

int floorSqrt(int n) {  // using binary search
    int low = 0, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((mid * mid) <= n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    cout << floorSqrt(5) << endl;
    cout << floorSqrtBuiltIn(5) << endl;
    cout << floorSqrt(9) << endl;
    cout << floorSqrtBuiltIn(9) << endl;
}