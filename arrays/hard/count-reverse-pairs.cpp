#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int low, int mid, int high) {
    int i = low, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= high) {
        if (vec[i] > vec[j]) {
            temp.push_back(vec[j]);
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
}

int countPairs(vector<int> &vec, int low, int mid, int high) {
    int j = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (j <= high && vec[i] > 2 * vec[j]) j++;
        cnt += (j - mid - 1);
    }
    return cnt;
}

int mergeSort(vector<int> &vec, int low, int high) {
    if (low >= high) return 0;
    int cnt = 0;
    int mid = low + (high - low) / 2;
    cnt += mergeSort(vec, low, mid);
    cnt += mergeSort(vec, mid + 1, high);
    cnt += countPairs(vec, low, mid, high);
    merge(vec, low, mid, high);
    return cnt;
}

int countReversePairs(vector<int> &vec) {
    return mergeSort(vec, 0, vec.size() - 1);
}

int main() {
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = countReversePairs(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}