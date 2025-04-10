#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
void selectionSort(vector<int> &vec) {
    for (int i=0;i<(int)vec.size();i++) {
        int mne = vec[i];
        int index = i;
        for (int j=i+1;j<(int)vec.size();j++) {
            if (vec[j]<mne) {
                mne = min(vec[j],vec[i]);
                index = j;
            }
        }
        swap(vec[index],vec[i]);
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
    selectionSort(vec);
    printVec(vec);
}