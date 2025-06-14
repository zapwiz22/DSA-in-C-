#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longestPalindromicSubsequence(string s) {
  string rev = s;
  reverse(rev.begin(), rev.end());
  int n = s.length();
  vector<int> prev(n + 1, 0), curr(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == rev[j - 1]) {
        curr[j] = 1 + prev[j - 1];
      } else {
        curr[j] = max(prev[j], curr[j - 1]);
      }
    }
    prev = curr;
  }
  return prev[n];
}

int main() {
  string s = "bbabcbcab";

  // Call the longestPalindromeSubsequence function and print the result
  cout << "The Length of Longest Palindromic Subsequence is "
       << longestPalindromicSubsequence(s);
  return 0;
}
