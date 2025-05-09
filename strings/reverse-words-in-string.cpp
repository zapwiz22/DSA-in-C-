#include <algorithm>
#include <iostream>
using namespace std;

string reverseStringWords(string &s) {
    reverse(s.begin(), s.end());
    int prev = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            reverse(s.begin() + prev, s.begin() + i);
            prev = i + 1;
        }
    }
    reverse(s.begin() + prev, s.end());
    return s;
}

// solution given in the striver's sheet
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

int main() {
    string s = "this is decent";
    // cout << reverseStringWords(s) << endl;
    cout << result(s) << endl;
    return 0;
}