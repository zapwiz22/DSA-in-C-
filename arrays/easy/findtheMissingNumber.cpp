#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> &vec) {
    int n = vec.size() + 1;
    int xOr = 0;
    for (int i = 1; i < n; i++) {
        xOr ^= vec[i - 1];
        xOr ^= i;
    }
    xOr ^= n;
    return xOr;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 6, 7, 8, 9};
    cout << "The missing element in the array is: " << findMissing(vec) << endl;
}