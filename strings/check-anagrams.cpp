#include <iostream>
#include <unordered_map>
using namespace std;

bool checkAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
        mp[t[i]]--;
    }
    for (auto it : mp) {
        if (it.second != 0) return false;
    }
    return true;
}

int main() {
    cout << checkAnagram("INTEGER", "TEGERNI") << endl;
    return 0;
}