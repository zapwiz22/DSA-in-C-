#include <iostream>
#include <vector>
using namespace std;

// using memoization
const int N = 1e6 + 10;
vector<int> dp(N, -1);
int fiboMemo(int n) {  // we need to return the nth fibonacci number
    if (n <= 2) return dp[n] = n - 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fiboMemo(n - 1) + fiboMemo(n - 2);
}

// using tabulation
int fiboTabu(int n) {
    if (n <= 2) return n - 1;
    int prev1 = 0, prev2 = 1;
    for (int i = 3; i <= n; i++) {
        int c = prev1 + prev2;
        prev1 = prev2;
        prev2 = c;
    }
    return prev2;
}

int main() {
    cout << fiboMemo(5) << endl;
    cout << fiboTabu(5) << endl;
}