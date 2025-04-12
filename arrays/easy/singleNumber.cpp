#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int xOr = 0;
        for (auto& val : nums) {
            xOr ^= val;
        }
        return xOr;
    }
};

int main() {
    vector<int> vec = {2, 2, 1};
    Solution ans;
    cout << ans.singleNumber(vec) << endl;
}