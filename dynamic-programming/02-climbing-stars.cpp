#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        // base case for 1 and 2 steps
        if (n == 1) return 1;
        if (n == 2) return 2;
        int prev1 = 1, prev2 = 2;
        for (int i = 3; i <= n; i++) {
            // possibilities of the ith step is the sum of possibilities of (i-1)th and (i-2)th step
            // as only 1 or 2 steps allowed
            int c = prev1 + prev2;
            prev1 = prev2;
            prev2 = c;
        }
        return prev2;
    }
};