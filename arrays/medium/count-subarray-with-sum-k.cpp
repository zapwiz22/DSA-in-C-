#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// the two pointer method fails for the vector containing negative values as increasing the right may reduce the sum 
// so using the hashmap method to solve this problem
int findSubarraysWithSumK(vector<int> &vec, int k) {
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        mp[sum]++;
        if (mp.find(sum-k)!=mp.end()) {
            cnt += mp[sum-k];
        }
    }
    return cnt;
}

int main() {
    vector arr = {3, 1, 2, 4};
    vector vec1 = {3, -3, 1, 1, 1};
    int k = 6;
    cout << "The number of subarrays with sum == k is: " << findSubarraysWithSumK(arr, k) << endl;
    cout << "The number of subarrays with sum == k is: " << findSubarraysWithSumK(vec1, 3) << endl;
    return 0;
}