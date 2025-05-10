#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int countOccurrence(vector<int> &vec, int target) {
    int cnt = 0;
    int last = upper_bound(vec.begin(), vec.end(), target) - vec.begin();
    int first = lower_bound(vec.begin(), vec.end(), target) - vec.begin();
    if (last == first)
        return cnt;
    else
        return last - first;
}

int main() {
    vector nums = {2, 2, 3, 3, 3, 3, 4};
    cout << countOccurrence(nums, 3) << endl;
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    cout << countOccurrence(arr,8) << endl;
    return 0;
}