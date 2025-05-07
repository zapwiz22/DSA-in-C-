#include <iostream>
using namespace std;

// variation 1: find the element at hte rth row and cth column position of the pascal triangle
int variation1(int row, int col) {
    int n = row - 1, r = col - 1;
    r = min(r, n - r);
    if (n == 0 || r == 0) return 1;
    int res = 1;
    for (int i = 1; i <= r; i++) {
        res = (res * (n - i + 1)) / i;
    }
    return res;
}

// variation 2: given the row number n, print the entire pascal triangle's row
void variation2(int N) {
    int n = N - 1;
    int curr = 1;
    cout << curr << " ";
    for (int i = 1; i <= n; i++) {
        curr *= n - i + 1;
        curr /= i;
        cout << curr << " ";
    }
    cout << endl;
    return;
}

// variation 3: entire pascal triangle till the Nth row
void variation3 (int N) {
    for (int i=1;i<=N;i++) {
        variation2(i);
    }
}

int main() {
    cout << variation1(5, 3) << endl;  // answer should be 6
    variation2(5); // 1 4 6 4 1
    variation3(5);
}