#include <iostream>
using namespace std;

class Solution {
  double helper(double x, long long n) {
    if (n == 0)
      return 1;
    if (n & 1) {
      double p = myPow(x, (n - 1) / 2);
      return p * p * x;
    } else {
      double p = myPow(x, n / 2);
      return p * p;
    }
  }

public:
  double myPow(double x, int n) {
    int sign = 1;
    long long pow = n;
    if (n < 0) {
      sign = -1;
      pow *= (-1);
    }
    if (sign < 0)
      return (double)(1 / helper(x, pow));
    else
      return helper(x, pow);
  }
};
