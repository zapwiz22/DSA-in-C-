#include <iostream>
using namespace std;

typedef long long ll;
class Solution {
  /* Binary Exponentiation */
  const int MOD = 1e9 + 7;
  ll modmul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
  ll binExpo(ll a, ll b) {
    if (b == 0)
      return 1;
    if (b & 1) { // odd
      ll p = binExpo(a, (b - 1) / 2);
      return 1LL * p * p % MOD * a % MOD;
    } else { // even
      ll p = binExpo(a, b / 2);
      return 1LL * p * p % MOD;
    }
  }

public:
  int countGoodNumbers(long long n) {
    if (n == 1)
      return 5;
    return 1ll * binExpo(5, (n + 1) / 2) % MOD * binExpo(4, n / 2) % MOD;
  }
};
