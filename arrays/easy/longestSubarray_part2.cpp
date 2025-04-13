#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* longest subarray with sum k containing both posititve and negative numbers in the original vector/array */
int longestSubarray(vector<int> &vec, int k) {
    unordered_map<int, int> pos;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        if (sum == k) {
            ans = max(ans, i + 1);
        }
        if (pos.find(sum - k) != pos.end()) {
            ans = max(ans, i + 1 - pos[sum - k]);
        }
        if (pos.find(sum) == pos.end()) {
            pos[sum] = i;
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {-1, 1, 1};
    int k = 1;
    cout << "the longest subarray having sum k is: " << longestSubarray(vec, k) << endl;
    return 0;
}