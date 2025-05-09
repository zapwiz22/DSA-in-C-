#include <iostream>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    return (1ll*n*(n+1))/2;
}

int main() {
    cout << countSubstrings("jayant") << endl;
    return 0;
}