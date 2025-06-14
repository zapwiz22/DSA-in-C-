#include <iostream>
#include <vector>
using namespace std;

int lcs(string s1, string s2) {
  int n = s1.length(), m = s2.length();
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i] == s2[j]) {
        curr[j] = 1 + prev[j - 1];
        ans = max(ans, curr[j]);
      } else {
        curr[j] = 0;
      }
    }
    prev = curr;
  }
  return ans;
}

int main() {
  string s1 = "abcjklp";
  string s2 = "acjkp";

  // Call the function to find and output the length of the Longest Common
  // Substring
  cout << "The Length of Longest Common Substring is " << lcs(s1, s2) << endl;

  return 0; // Return 0 to indicate successful program execution
}
