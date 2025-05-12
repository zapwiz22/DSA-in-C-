#include <cmath>
#include <iostream>
using namespace std;

void printPrimes(int n) {
    for (int i = 2; i < (int)sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) cout << n;
    cout << endl;
    return;
}

int main() {
    printPrimes(780);
    printPrimes(24);
    printPrimes(64);
    return 0;
}