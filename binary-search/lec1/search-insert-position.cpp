#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector vec1 = {1, 2, 4, 7};
    // insert position for 6 is
    cout << lower_bound(vec1.begin(), vec1.end(), 6) - vec1.begin() << endl;
    vector vec2 = {1, 2, 4, 7};
    // insert position for 2 is
    cout << lower_bound(vec2.begin(), vec2.end(), 2) - vec2.begin() << endl;
    return 0;
}