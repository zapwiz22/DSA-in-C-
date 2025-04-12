#include <iostream>
#include <vector>
using namespace std;

// O(m+n)
vector<int> findUnion(vector<int> &vec1, vector<int> &vec2) {
    vector<int> ans;
    int i = 0, j = 0;
    int n = vec1.size(), m = vec2.size();
    while (i < n && j < m) {
        if (vec1[i] <= vec2[j]) {
            if (ans.size() == 0 or ans[ans.size() - 1] != vec1[i]) {
                ans.push_back(vec1[i]);
            }
            i++;
        } else {
            if (ans.size() == 0 or ans[ans.size() - 1] != vec2[j]) {
                ans.push_back(vec2[j]);
            }
            j++;
        }
    }
    while (i < n) {
        ans.push_back(vec1[i]);
        i++;
    }
    while (j < m) {
        ans.push_back(vec2[j]);
        j++;
    }
    return ans;
}

int main() {
    vector<int> vec1 = {1, 3, 5, 8};
    vector<int> vec2 = {2, 4, 5, 6, 9};
    vector<int> unionResult = findUnion(vec1, vec2);
    for (auto &val : unionResult) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}