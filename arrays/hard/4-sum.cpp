#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> quadruple(vector<int> &vec, int target) {
    int n = vec.size();
    vector<vector<int>> res;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && vec[i] == vec[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > (i+1) && vec[j] == vec[j - 1]) continue;
            int k = j + 1, l = n - 1;
            while (k < l) {
                int sum = vec[i] + vec[j] + vec[k] + vec[l];
                if (sum < target)
                    k++;
                else if (sum > target)
                    l--;
                else {
                    res.push_back({vec[i], vec[j], vec[k], vec[l]});
                    k++, l--;
                    while (k < l && vec[k] == vec[k - 1]) k++;
                    while (k < l && vec[l] == vec[l + 1]) l--;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = quadruple(nums, target);
    for (auto &vec : ans) {
        for (auto &val : vec) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}