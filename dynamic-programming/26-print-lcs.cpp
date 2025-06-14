#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
  int n = text1.size();
  int m = text2.size();
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (text1[i - 1] == text2[j - 1]) {
        dp2[i][j] = 1 + dp2[i - 1][j - 1];
      } else {
        dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
      }
    }
  }
  return dp2[n][m];
}

void printLCS(string text1, string text2) {
  int len = longestCommonSubsequence(text1, text2);
  string res = "";
  for (int i = 0; i < len; i++)
    res += '0';
  int i = text1.length(), j = text2.length();
  int index = len - 1;
  while (i > 0 and j > 0) {
    if (text1[i - 1] == text2[j - 1]) {
      res[index] = text1[i - 1];
      index--;
      i--;
      j--;
    } else if (text1[i - 1] > text2[j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  cout << res << endl;
  return;
}

int main() {
  string text1 = "abcde", text2 = "bdgek";
  printLCS(text1, text2);
}
