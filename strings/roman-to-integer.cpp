#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        int val = 0;
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (i<s.length()-1 && mp[s[i+1]]>mp[s[i]]) {
                val -= mp[s[i]];
            } else {
                val += mp[s[i]];
            }
        }
        return val;
    }
};

int main() {
}