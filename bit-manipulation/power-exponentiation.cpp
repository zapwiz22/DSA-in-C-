#include <iostream>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    // if (b<0) return 1/res; then float shoudl be the returning type
    return res;
}

int main() {
    cout << binpow(3, 9) << endl;
    cout << binpow(3, 4) << endl;
    return 0;
}