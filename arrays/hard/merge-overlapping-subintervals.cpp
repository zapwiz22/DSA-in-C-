#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mergeOverlapping(vector<vector<int>> &vec) {
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;
    for (int i = 0; i < vec.size(); i++) {
        int start = vec[i][0], end = vec[i][1];
        if (!ans.empty() && start <= ans.back()[1]) ans.back()[1] = max(ans.back()[1], end);
        else ans.push_back({start, end});
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlapping(arr);
    for (auto &vec : ans) {
        for (auto &val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}