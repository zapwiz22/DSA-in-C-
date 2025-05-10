#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> floorANDceil(vector<int> &vec, int num) {
    // return floor,ceil
    int ceil = *lower_bound(vec.begin(), vec.end(), num);
    int floor;
    auto itFloor = upper_bound(vec.begin(), vec.end(), num);
    if (itFloor == vec.begin())
        floor = -1;
    else
        floor = *(--itFloor);
    return {floor, ceil};
}

int main() {
    vector nums = {3, 4, 4, 7, 8, 10};
    vector<int> ans = floorANDceil(nums, 5);
    for (auto &val : ans) cout << val << " ";
    cout << endl;
    return 0;
}