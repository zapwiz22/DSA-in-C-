#include <iostream>
#include <vector>
using namespace std;

// O(n)
void merge(vector<int> &vec, int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (vec[i] < vec[j]) {
            temp.push_back(vec[i]);
            i++;
        } else {
            temp.push_back(vec[j]);
            j++;
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
    for (int i = 0; i < (int)temp.size(); i++) {
        vec[low + i] = temp[i];
    }
}

// O(n*logn)
void mergeSortAlgo(vector<int> &vec, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSortAlgo(vec, low, mid);
    mergeSortAlgo(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

void mergeSort(vector<int> &vec) {
    mergeSortAlgo(vec, 0, vec.size() - 1);
}

void printVec(vector<int> &vec) {
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {6, 4, 8, 1, 4};
    printVec(vec);
    mergeSort(vec);
    printVec(vec);
}