#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> divisors(int n) {
    vector<int> res;
    for (int i = 1; i < (int)sqrt(n) + 1; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != (n / i)) res.push_back(n / i);
        }
    }
    return res;
}

int main() {
    vector<int> ans = divisors(20);
    for (auto &val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}