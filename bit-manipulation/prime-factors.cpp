#include <iostream>
using namespace std;

void printPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    cout << endl;
    return;
}

int main() {
    printPrimes(13);
    printPrimes(24);
    printPrimes(64);
    return 0;
}