#include <iostream>
#include <vector>
using namespace std;

/* two pointer approach for calculating the longest subarray with a particular sum */
int longestSubarrayLength(vector<int> &vec, int k) {
    int i = 0, j = 0;
    int sum = 0;
    int ans = 0;
    while (i < vec.size()) {
        sum += vec[i];
        while (sum > k && j <= i) {
            sum -= vec[j];
            j++;
        }
        if (sum == k) {
            ans = max(ans, i - j + 1);
        }
        i++;
    }
    return ans;
}

int main() {
    vector<int> a = {2, 3, 5, 1, 9};
    int k = 10;
    cout << "the longest subarrray with sum equal to k is: " << longestSubarrayLength(a, k) << endl;
    return 0;
}