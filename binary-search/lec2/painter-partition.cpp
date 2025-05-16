#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int largestMinDistance(vector<int> &boards, int k) {
  int low = *max_element(boards.begin(), boards.end()),
      high = accumulate(boards.begin(), boards.end(), 0ll);
  int ans;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int curr = 0, cnt = 0;
    for (auto &val : boards) {
      curr += val;
      if (curr > mid) {
        cnt++;
        curr = val;
      }
    }
    if (curr)
      cnt++;
    if (cnt <= k) {
      ans = mid, high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> boards = {10, 20, 30, 40};
  int k = 2;
  int ans = largestMinDistance(boards, k);
  cout << "The answer is: " << ans << "\n";
  return 0;
}
