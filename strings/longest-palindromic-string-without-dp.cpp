#include <iostream>
using namespace std;

class Solution {
   private:
    string expandAboutCenter(int i, int j, string s) {
        int left = i, right = j;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            left--, right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

   public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            string odd = expandAboutCenter(i, i, s);
            if (odd.size() > ans.size()) ans = odd;
            string even = expandAboutCenter(i, i + 1, s);
            if (even.size() > ans.size()) ans = even;
        }
        return ans;
    }
};

int main() {
    cout << (new Solution)->longestPalindrome("babcd") << endl;
    return 0;
}