#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countXorK(vector<int> &vec, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int cnt = 0;
    int exor = 0;
    for (int i = 0; i < vec.size(); i++) {
        exor ^= vec[i];
        cnt += mp[exor ^ k];
        mp[exor]++;
    }
    return cnt;
}

int main() {
    vector nums = {4, 2, 2, 6, 4};
    cout << countXorK(nums, 6) << endl;
    vector nums2 = {5, 6, 7, 8, 9};
    cout << countXorK(nums2, 5) << endl;
    return 0;
}