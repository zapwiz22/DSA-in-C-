#include <iostream>
#include <vector>
using namespace std;

// O(n)
int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[low];
    int i = low + 1, j = high;
    while (i < j) {
        while (vec[i] <= pivot && i < high) {
            i++;
        }
        while (vec[j] > pivot && j >= low) {
            j--;
        }
        if (i < j) {
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[low], vec[j]);
    return j;
}

// O(n*logn)
void quickSortAlgo(vector<int> &vec, int low, int high) {
    if (low >= high) return;
    int q = partition(vec, low, high);
    quickSortAlgo(vec, low, q - 1);
    quickSortAlgo(vec, q + 1, high);
}

void quickSort(vector<int> &vec) {
    quickSortAlgo(vec, 0, vec.size() - 1);
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
    quickSort(vec);
    printVec(vec);
}