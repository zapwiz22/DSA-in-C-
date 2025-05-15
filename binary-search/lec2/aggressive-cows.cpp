#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int aggressiveCows(vector<int> stalls, int k) {
  vector<int> pos = stalls;
  sort(pos.begin(), pos.end());
  int low = 1, high = pos[pos.size() - 1] - pos[0];
  for (int i = pos.size() - 1; i >= 1; i--) {
    pos[i] = pos[i] - pos[i - 1];
  }
  pos[0] = 0;
  int ans;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int cnt = 1, curr = 0;
    for (auto &val : pos) {
      curr += val;
      if (val >= mid) {
        cnt++;
        curr = 0;
      }
    }
    if (curr >= mid)
      cnt++;
    if (cnt >= k) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int main() {
  vector<int> stalls = {0, 3, 4, 7, 10, 9};
  int k = 4;
  int ans = aggressiveCows(stalls, k);
  cout << "The maximum possible minimum distance is: " << ans << "\n";
  return 0;
}
