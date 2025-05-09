#include <iostream>
using namespace std;

class Solution {
   public:
    string largestOddNumber(string num) {
        int index = -1;  // index of the first odd number encountered from back
        for (int i = num.length() - 1; i >= 0; i--) {
            int ch = num[i] - '0';
            if (ch & 1) {
                index = i;
                break;
            }
        }
        if (index == -1) return "";
        return to_string(stoi(num.substr(0,index+1)));
        // string result = "";
        // for (int i=0;i<=index;i++) {
        //     if (result=="" && num[i]!='0') result += num[i];
        //     else if (result!="") result+=num[i];
        // }
        // return result;
    }
};

int main() {
    string num = "0052";
    cout << (new Solution)->largestOddNumber(num) << endl;
}