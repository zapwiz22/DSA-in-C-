#include <climits>
#include <iostream>
using namespace std;

class Solution {
   public:
    int myAtoi(string s) {
        if (s.length() == 0) return 0;
        int index = -1;
        long long int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '-' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9')) {
                index = i;
                break;
            } else if (s[i] == ' ')
                continue;
            else
                return 0;
        }
        if (index == -1) return 0;
        int sign = 1;
        if (s[index] == '-') {
            sign = -1;
        } else if (s[index] == '+')
            sign = 1;
        else {
            result = (s[index] - '0');
        }
        for (int i = index + 1; i < s.length(); i++) {
            if (s[i] >= '0' and s[i] <= '9') {
                result = (result * 10) + (s[i] - '0');
            } else {
                break;
            }
            if (sign == 1)
                if (result > INT_MAX) return INT_MAX;
            if (sign == -1)
                if (result * sign < INT_MIN) return INT_MIN;
        }
        return sign * result;
    }
};

int main() {
    cout << (new Solution)->myAtoi("  +95abc") << endl;
    return 0;
}