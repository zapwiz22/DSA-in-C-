#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// method to find the pref product and suff product about any number and storing its max
// when product becomes zero reset and for odd number of negative numbers we are already selecting the maximum of pref and suff about it
int maxProductSubarray(vector<int> &vec) {
    int ans = INT_MIN;
    int pref = 1, suff = 1;
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        if (pref == 0) pref = 1;
        if (suff == 0) suff = 1;
        pref *= vec[i];
        suff *= vec[n - i - 1];
        ans = max({ans, suff, pref});
    }
    return ans;
}

// second method is to use similar to something like kadane's algo
// ans will be the maximum of everything if all positives no zeroes and even negatives
// it will be more clear by the below code
// prod1 alwasy stores the maximum and the prod2 the minimum product
// so if a negative number encounters prod2* negative becomes a postitive numbe rwhich if large enough can be stored in prod1
// greedy algorithm
int maxProductSubarray_KA(vector<int> &vec) {
    int ans = vec[0], prod1 = vec[0], prod2 = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        int temp = max({vec[i], prod1 * vec[i], prod2 * vec[i]});
        prod2 = min({vec[i], prod1 * vec[i], prod2 * vec[i]});
        prod1 = temp;
        ans = max(ans, prod1);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubarray(arr) << "\n";
    cout << maxProductSubarray_KA(arr) << endl;
    return 0;
}