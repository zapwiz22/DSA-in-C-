#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
void bubbleSort(vector<int> &vec) {
    for (int i = 0; i < (int)vec.size(); i++) {
        for (int j = 0; j < (int)vec.size() - i - 1; j++) {
            if (vec[j + 1] < vec[j]) {
                swap(vec[j + 1], vec[j]);
            }
        }
    }
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
    bubbleSort(vec);
    printVec(vec);
}