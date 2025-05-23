#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    if (arr[0] > k)
      return k;
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if ((arr[mid] - mid - 1) < k) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return arr[high] + (k - (arr[high] - high - 1));
  }
};
