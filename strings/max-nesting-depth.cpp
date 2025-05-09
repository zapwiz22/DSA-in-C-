#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
   public:
    int maxDepth(string s) {
        int cnt = 0;
        int res = 0;
        for (char &ch : s) {
            if (ch == '(')
                cnt++;
            else if (ch == ')')
                cnt--;
            res = max(res, cnt);
        }
        return res;
    }
};

int main() {
    cout << (new Solution)->maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    return 0;
}