#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int left = -1, right = 0;
    int mxe = 0;
    while (right < s.length()) {
      mp[s[right]]++;
      if (mp[s[right]] > 1) {
        left++;
        while (left < right and s[left] != s[right]) {
          mp[s[left]]--;
          left++;
        }
        if (s[left] == s[right]) {
          mp[s[left]]--;
        }
      }
      mxe = max(mxe, right - left);
      right++;
    }
    return mxe;
  }
};

int main() {
  Solution sol;
  cout << sol.lengthOfLongestSubstring("tmmzuxt");
  cout << endl;
  return 0;
}
