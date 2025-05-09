#include <iostream>
using namespace std;

class Solution {
   public:
    string removeOuterParentheses(string s) {
        int open = 0, closed = 0;
        string result;
        for (char &ch : s) {
            if (ch == '(')
                open++;
            else
                closed++;
            if (open == 1 and closed == 0)
                continue;
            else if (open == closed) {
                open = 0, closed = 0;
                continue;
            } else
                result += ch;
        }
        return result;
    }
};

int main() {
    string s = "(()())(())";
    Solution ans;
    cout << ans.removeOuterParentheses(s) << endl;
    return 0;
}