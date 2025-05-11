#include <iostream>
#include <vector>
using namespace std;

int singleElement(vector<int> &vec) {
    int exor = 0;
    for (auto &val : vec) {
        exor ^= val;
    }
    return exor;
}

int main() {
    vector nums = {1, 4, 2, 1, 2};
    cout << singleElement(nums) << endl;
    return 0;
}