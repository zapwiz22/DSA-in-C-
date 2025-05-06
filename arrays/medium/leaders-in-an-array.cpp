#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void leadersArray(vector<int> &vec) {
    int mxe = INT_MIN;
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] > mxe) {
            cout << vec[i] << " ";
        }
        mxe = max(mxe, vec[i]);
    }
    cout << endl;
}

int main() {
    vector<int> vec1 = {4, 7, 1, 0};
    vector<int> vec2 = {10, 22, 12, 3, 0, 6};
    leadersArray(vec1);
    leadersArray(vec2);
}