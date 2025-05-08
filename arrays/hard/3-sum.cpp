#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &vec) {
    vector<vector<int>> res;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && vec[i] == vec[i - 1]) continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = vec[i] + vec[j] + vec[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                res.push_back({vec[i], vec[j], vec[k]});
                j++, k--;
                while (j < k && vec[j] == vec[j - 1]) j++;
                while (j < k && vec[k] == vec[k + 1]) k--;
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        for (auto &val : it) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}