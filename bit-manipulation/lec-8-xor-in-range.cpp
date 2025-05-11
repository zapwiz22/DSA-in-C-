#include <iostream>
using namespace std;

int xorInRange(int n) {
    // xor from 1 to n;
    if (n % 4 == 1) {
        return 1;
    } else if (n % 4 == 2) {
        return n + 1;
    } else if (n % 4 == 3) {
        return 0;
    } else {
        return n;
    }
}

int main() {
    cout << xorInRange(6) << endl;
    cout << xorInRange(7) << endl;
    cout << xorInRange(8) << endl;
    cout << xorInRange(9) << endl;
    return 0;
}