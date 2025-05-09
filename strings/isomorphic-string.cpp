#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for (int i = 0; i < s.length(); i++) {
            char ch1 = s[i], ch2 = t[i];
            if (mp1.find(ch1) == mp1.end() && mp2.find(ch2) == mp2.end()) {
                mp1[ch1] = ch2, mp2[ch2] = ch1;
            } else if (mp1[ch1] != ch2 or mp2[ch2] != ch1)
                return false;
        }
        return true;
    }
};

int main() {
    cout << (new Solution)->isIsomorphic("13", "42") << endl;
    return 0;
}