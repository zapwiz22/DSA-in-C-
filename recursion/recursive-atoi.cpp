#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Solution {
  int helper(string &s, int index, int sign, long long result, bool started) {
    if (index >= s.length())
      return sign * result;

    char c = s[index];

    if (!started && c == ' ') {
      return helper(s, index + 1, sign, result, false);
    }

    if (!started && (c == '-' || c == '+')) {
      sign = (c == '-') ? -1 : 1;
      return helper(s, index + 1, sign, result, true);
    }

    if (isdigit(c)) {
      int digit = c - '0';
      long long newresult = result * 10 + digit;

      if (sign == 1 && newresult >= INT_MAX)
        return INT_MAX;
      if (sign == -1 && -newresult <= INT_MIN)
        return INT_MIN;

      return helper(s, index + 1, sign, newresult, true);
    }

    return sign * result;
  }

public:
  int myAtoi(string s) { return helper(s, 0, 1, 0, false); }
};
