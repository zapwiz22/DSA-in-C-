#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int usingSorting(vector<int> vec) {
    // directly using the sort function in STL 
    sort(vec.begin(),vec.end());
    return vec[vec.size()-1];
}

int iteratingMaximum(vector<int> &vec) {
    int mxe = vec[0];
    for (int i=1;i<vec.size();i++) {
        if (mxe<vec[i]) {
            mxe = vec[i];
        }
    }
    return mxe;
}

int main() {
    vector<int> vec = {4,2,8,1,5};
    cout << "Max element using different approaches: \n";
    cout << "Using Sorting: " << usingSorting(vec) << endl;
    cout << "Iterating and finding Maximum: " << iteratingMaximum(vec) << endl;
    cout << "Directly using the Max STL function: " << *max_element(vec.begin(),vec.end()) << endl;
}
