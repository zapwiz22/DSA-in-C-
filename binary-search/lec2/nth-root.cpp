#include <iostream>
using namespace std;

int nthRoot(int num, int n) {
    int low = 0, high = num;
    while (low <= high) {
        int val = 1;
        int mid = low + (high - low) / 2;
        for (int i = 0; i < n; i++) {
            val *= mid;
        }
        if (val == num) {
            return mid;
        } else if (val < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout << nthRoot(27, 3) << endl;
    cout << nthRoot(69, 4) << endl;
    return 0;
}