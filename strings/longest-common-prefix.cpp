#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string> &strs) {
        int mne = INT_MAX;
        for (auto &str : strs) mne = min(mne, (int)str.length());
        string result = "";
        for (int i = 0; i < mne; i++) {
            char curr = strs[0][i];
            for (auto &str : strs) {
                if (str[i] != curr) return result;
            }
            result += curr;
        }
        return result;
    }
};

int main() {
    vector<string> st = {"flowers", "flow", "fly", "flight"};
    cout << (new Solution)->longestCommonPrefix(st) << endl;
    return 0;
}