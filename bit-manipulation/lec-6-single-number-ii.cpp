#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// T.C :- O(32N) S.C. :- O(1)
int singleElement(vector<int> &vec) {
    int ans = 0;
    for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
        int cnt = 0;
        for (auto &val : vec) {
            cnt += ((val & (1 << bitIndex)) ? 1 : 0);
        }
        if (cnt % 3) ans = ans | (1 << bitIndex);
    }
    return ans;
}

// T.C. :- O(NlogN + N/3) S.C. :- O(1)
int singleElementOptimised(vector<int> vec) {
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i += 3) {
        if (vec[i] != vec[i - 1]) return vec[i - 1];
    }
    return vec[vec.size() - 1];
}

/** most optimised code
 * using bucket method
 * T.C. :- O(n)  S.C. :- O(1)
 */
int singleElementFinal(vector<int> &vec) {
    int ones = 0, twos = 0;
    for (auto &val : vec) {
        ones = (ones^val)&(~twos);
        twos = (twos^val)&(~ones);
    }
    return ones;
}

int main() {
    // every number appears thrice except one
    vector nums = {5, 5, 5, 3, 4, 4, 4};
    cout << singleElement(nums) << endl;
    cout << singleElementOptimised(nums) << endl;
    cout << singleElementFinal(nums) << endl;
    return 0;
}