#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char& ch : s) {
            freq[ch]++;
        }
        vector<pair<int, char>> pr;
        for (auto& [ch, count] : freq) {
            pr.push_back({count, ch});
        }
        sort(pr.rbegin(), pr.rend());
        string result = "";
        for (auto& [count, ch] : pr) {
            // result += string(count, ch);
            result.append(count,ch);
        }
        return result;
    }
};

int main() {
    cout << (new Solution)->frequencySort("tree") << endl;
    return 0;
}