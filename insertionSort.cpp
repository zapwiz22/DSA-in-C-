#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
void insertionSort(vector<int> &vec) {
    for (int i=0;i<(int)vec.size();i++) {
        int key = vec[i];
        int j = i-1;
        while (j>=0) {
            if (vec[j]>key) {
                vec[j+1] = vec[j];
            } else {
                break;
            }
            j--;
        }
        vec[j+1] = key;
    }
}

void printVec(vector<int> &vec) {
    for (int i=0;i<(int)vec.size();i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {6,4,8,1,4};
    printVec(vec);
    insertionSort(vec);
    printVec(vec);
}