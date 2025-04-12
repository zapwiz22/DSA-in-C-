#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int secondLargest(vector<int> &vec) {
    int largest = -1, secondLargest = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > largest) {
            secondLargest = largest;
            largest = vec[i];
        } else if (vec[i] > secondLargest) {
            secondLargest = vec[i];
        }
    }
    if (largest == secondLargest) return -1;
    return secondLargest;
}

int secondSmallest(vector<int> &vec) {
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < smallest) {
            secondSmallest = smallest;
            smallest = vec[i];
        } else if (vec[i] < secondSmallest) {
            secondSmallest = vec[i];
        }
    }
    if (secondSmallest == INT_MAX or secondSmallest == smallest) return -1;
    return secondSmallest;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 4, 2};
    cout << "second largest is: " << secondLargest(vec) << endl;
    cout << "second smallest is: " << secondSmallest(vec) << endl;
}