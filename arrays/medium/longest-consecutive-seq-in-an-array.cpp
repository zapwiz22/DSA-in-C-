#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// O(NlogN) approach to solve this problem
int longestConsecutiveSequenceLen(vector<int> &vec) {
    sort(vec.begin(), vec.end());
    int ans = 0;
    int curr = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[i - 1] + 1) {
            curr++;
        } else {
            curr = 1;
        }
        ans = max(ans, curr);
    }
    return ans;
}

// O(n) solution using unordered_set
int longestConsSequenceSet(vector<int> &vec) {
    if (vec.size() == 0) return 0;
    unordered_set<int> st;
    for (auto &val : vec) st.insert(val);

    int longest = 1;
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int val = it;
            while (st.find(val + 1) != st.end()) {
                val = val + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    vector<int> vec1 = {100, 200, 1, 3, 2, 4};
    cout << longestConsecutiveSequenceLen(vec1) << endl;
    cout << longestConsSequenceSet(vec1) << endl;
    return 0;
}