#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int func(vector<vector<int>> &points, int curr, int index, int days) {
  if (days == points.size()) {
    return curr;
  }
  int ans1, ans2, ans3;
  if (index != 0)
    ans1 = func(points, curr + points[days][0], 0, days + 1);
  if (index != 1)
    ans2 = func(points, curr + points[days][1], 1, days + 1);
  if (index != 2)
    ans3 = func(points, curr + points[days][2], 2, days + 1);
  return max({ans1, ans2, ans3});
}

int sol(vector<vector<int>> &points) {
  int mxe = 0, prev = 0;
  int last = -1;
  int n = points.size();
  for (int i = 0; i < n; i++) {
    int used = -1;
    for (int j = 0; j < 3; j++) {
      if (last != j) {
        if (prev + points[i][j] > mxe) {
          mxe = prev + points[i][j];
          used = j;
        }
      }
    }
    prev = mxe;
    last = used;
  }
  return mxe;
}

int main() {
  // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
  int n = points.size(); // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the
  // result
  cout << func(points, 0, -1, 0) << endl;
  cout << sol(points);
}
