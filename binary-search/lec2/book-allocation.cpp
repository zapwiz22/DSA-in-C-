#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int findPages(vector<int> &arr, int m) {
  int n = arr.size();
  int low = *max_element(arr.begin(), arr.end()),
      high = accumulate(arr.begin(), arr.end(), 0ll);
  int ans;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int curr = 0, cnt = 0;
    for (auto &val : arr) {
      curr += val;
      if (curr > mid) {
        cnt++;
        curr = val;
      }
    }
    if (curr)
      cnt++;
    if (cnt <= m) {
      ans = mid, high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {25, 46, 28, 49, 24};
  int n = 5;
  int m = 4;
  int ans = findPages(arr, m);
  cout << "The answer is: " << ans << "\n";
  return 0;
}
