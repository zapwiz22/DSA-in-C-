#include <iostream>
#include <vector>
using namespace std;

int frogJump(int n, vector<int> &height) {
    if (n == 2) return height[1] - height[0];
    int prev1 = 0;
    int prev2 = abs(height[1] - height[0]);
    for (int i = 2; i < n; i++) {
        int c = min(prev1 + abs(height[i] - height[i - 2]), prev2 + abs(height[i] - height[i - 1]));
        prev1 = prev2;
        prev2 = c;
    }
    return prev2;
}

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    cout << frogJump(n, height) << endl;
    return 0;
}