#include <iostream>
#include <vector>
using namespace std;

vector<bool> sievePrime(int n) {
    vector<bool> prime(n, true);
    prime[0] = false, prime[1] = false;
    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

/* leetcode problem solution */
class Solution {
   public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;
        vector<bool> prime(n, true);
        int cnt = 0;
        prime[0] = false, prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (long long j = 1ll * i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};