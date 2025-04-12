#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int> &vec, int val) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == val) return true;
    }
    return false;
}

int main() {
    vector<int> vec = {1, 5, 3, 2, 6};
    cout << "does 5 exist in vec: " << linearSearch(vec, 5) << endl;  // 1 for true and 0 for false
    cout << "does 9 exist in vec: " << linearSearch(vec, 9) << endl;  // 1 for true and 0 for false
}