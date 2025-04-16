#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/* maximum subarray sum along with the array which gives that sum  */
/* again using kadane's algorithm to find the maximum subarray */
/* O(n) */
int maxSubarraySum(vector<int> &nums) {
    int sum = 0;
    int res = INT_MIN;
    int start = 0, end = 0, tempStart = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum>res) {
            res = sum;
            start = tempStart;
            end = i;
        }
        if (sum < 0) {
            sum = 0;
            tempStart = i+1;
        }
    }
    for (int i=start;i<=end;i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return res;
}

int main() {
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubarraySum(vec);
    cout << ans << endl;
    return 0;
}