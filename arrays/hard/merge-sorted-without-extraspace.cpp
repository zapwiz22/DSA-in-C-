#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// merge sorted such that the first n integers are in vec1 and the rest m integers in vec2
void mergeSorted(vector<int> &vec1, vector<int> &vec2) {
    int n = vec1.size(), m = vec2.size();
    int i = n - 1, j = 0;
    while (vec1[i] > vec2[j] && i >= 0 && j < m) {
        swap(vec1[i], vec2[j]);
        i--, j++;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
}

int main() {
    vector arr1 = {1, 4, 8, 10};
    vector arr2 = {2, 3, 9};
    int n = 4, m = 3;
    mergeSorted(arr1, arr2);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}