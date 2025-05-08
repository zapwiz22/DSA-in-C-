#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * can also be done using pure maths
 * as two variables and two equations from sum of n and sum of squares of n
 */

vector<int> findMissingRepeatingNumbers(vector<int> &vec) {
    int xr = 0;
    for (int i = 1; i <= vec.size(); i++) {
        xr ^= i;
        xr ^= vec[i - 1];
    }
    // the first differing bit
    int bit = xr & (~(xr - 1));

    // with the bit set -> one
    // not that bit set --> zero
    int one = 0, zero = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] & bit != 0)
            one ^= vec[i];
        else
            zero ^= vec[i];
        if ((i + 1) & bit != 0)
            one ^= (i + 1);
        else
            zero ^= (i + 1);
    }

    // returning {repeating,missing};
    if (count(vec.begin(), vec.end(), one) > 1)
        return {one, zero};
    else
        return {zero, one};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}