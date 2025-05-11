#include <iostream>
using namespace std;

int bitFlipsConvert(int a, int b) {
    return __builtin_popcountll(a ^ b); // __builtin_popcountll or __builtin_popcount counts the number of setbits
}

int main() {
    cout << bitFlipsConvert(10, 7) << endl;
    cout << bitFlipsConvert(3, 4) << endl;
    return 0;
}