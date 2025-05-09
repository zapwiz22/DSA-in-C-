#include <iostream>
using namespace std;

class Solution {
   public:
    bool rotateString(string s, string goal) {
        for (int i = 0; i < goal.length(); i++) {
            string rotated = goal.substr(i, goal.length()) + goal.substr(0, i);
            if (s == rotated) return true;
        }
        return false;
    }
};

int main() {
    cout << (new Solution)->rotateString("abcde", "cdeab") << endl;
    return 0;
}