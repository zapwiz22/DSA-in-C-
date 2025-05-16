#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &vec, int low, int mid, int high) {
  int i = low, j = mid + 1;
  int cnt = 0;
  vector<int> temp;
  while (i <= mid && j <= high) {
    if (vec[i] > vec[j]) {
      temp.push_back(vec[j]);
      cnt += mid - i + 1;
      j++;
    } else {
      temp.push_back(vec[i]);
      i++;
    }
  }
  while (i <= mid) {
    temp.push_back(vec[i]);
    i++;
  }
  while (j <= high) {
    temp.push_back(vec[j]);
    j++;
  }
  for (int i = low; i <= high; i++) {
    vec[i] = temp[i - low];
  }
  return cnt;
}

int mergeSort(vector<int> &vec, int low, int high) {
  if (low >= high)
    return 0;
  int cnt = 0;
  int mid = low + (high - low) / 2;
  cnt += mergeSort(vec, low, mid);
  cnt += mergeSort(vec, mid + 1, high);
  return merge(vec, low, mid, high) + cnt;
}

// merge sort like function to count the number of inversions
int numberOfInversions(vector<int> &vec) {
  return mergeSort(vec, 0, vec.size() - 1);
}

int main() {
  vector nums = {5, 4, 3, 2, 1};
  cout << numberOfInversions(nums) << endl;
  return 0;
}
