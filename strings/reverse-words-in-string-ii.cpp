#include <iostream>
#include <vector>
using namespace std;

/**
 * another approach is to store the words in a vector using the same logic and then create the string with the words in the vector reversed
 */

class Solution {
   public:
    string reverseWords(string s) {
        string nw;
        bool ok = true;
        for (char &ch : s) {
            if (ok && ch == ' ')
                continue;
            else if (!ok && ch == ' ') {
                ok = true;
                nw += ch;
            } else {
                ok = false;
                nw += ch;
            }
        }
        return result(nw);
    }

   private:
    string result(string s) {
        string temp = "", ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                temp += s[i];
            else {
                if (ans != "")
                    ans = temp + ' ' + ans;
                else
                    ans = temp;
                temp = "";
            }
        }
        if (temp != "")
            if (ans != "")
                ans = temp + " " + ans;
            else
                ans = temp;
        return ans;
    }
};

int main() {
    cout << (new Solution)->reverseWords("  hello world  ") << endl;
    return 0;
}