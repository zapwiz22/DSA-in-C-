#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int N = 1e6 + 10;
vector<int> smallestPrime(N);

void smallestPrimeFactor() {
    iota(smallestPrime.begin(), smallestPrime.end(), 0);
    int n = smallestPrime.size();
    for (int i = 2; i < n; i++) {
        if (smallestPrime[i] == i) {
            for (long long j = 1ll * i * i; j < n; j += i) {
                smallestPrime[j] = i;
            }
        }
    }
}

void printPrimeFactorization(int n) {
    int firstPrime = smallestPrime[n];
    for (int i = firstPrime; i < (int)sqrt(n) + 1; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
    }
    if (n > 1) cout << n;
    cout << endl;
    return;
}

// t.c. :- O(nloglogn + klog2n)
// s.c. :- O(1e6)
void primeFactorization(int n) {
    while (n != 1) {
        int spf = smallestPrime[n];
        cout << spf << " ";
        n /= spf;
    }
    cout << endl;
}

int main() {
    smallestPrimeFactor();
    printPrimeFactorization(64);
    printPrimeFactorization(17);

    primeFactorization(64);
    primeFactorization(780);
}