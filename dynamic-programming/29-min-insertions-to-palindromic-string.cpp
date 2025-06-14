#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/** the theory is that for min insertions
 * to make a string palindrome
 * find the longest palindromic subsequence and then
 * add the remaining chars in the opposite order at the required positions
 */
int minInsertion(string s) {
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
  int len = prev[n];
  return n - len;
}

int main() {
  string s = "abcaa";

  // Call the minInsertion function and print the result
  cout << "The Minimum insertions required to make string palindrome: "
       << minInsertion(s);
  return 0;
}
