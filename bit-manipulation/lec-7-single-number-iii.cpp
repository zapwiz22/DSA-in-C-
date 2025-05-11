#include <iostream>
#include <vector>
using namespace std;

// Find the two numbers appearing odd number of times.
vector<int> singleNumber(vector<int> &vec) {
    // using concept of bukcets
    long long exor = 0;  // long long because if exor comes to be -2^31 then (-2^31)^(-2^31-1) will overflow
    for (auto &val : vec) {
        exor ^= val;
    }
    int diffBit = (exor & (exor - 1)) ^ exor;
    int ones = 0, twos = 0;
    for (auto &val : vec) {
        if (val & diffBit)
            ones ^= val;
        else
            twos ^= val;
    }
    return {ones, twos};
}

int main() {
    vector nums = {2, 2, 4, 14, 3, 3, 5, 5};
    vector ans = singleNumber(nums);
    for (auto &val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}