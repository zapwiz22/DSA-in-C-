#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> powerSet(vector<int> &vec) {
    int n = vec.size();
    vector<vector<int>> res;
    for (int i=0;i<(1<<n);i++) {
        vector<int> temp;
        for (int j=0;j<n;j++) {
            if (i&(1<<j)) temp.push_back(vec[j]);
        }
        res.push_back(temp);
    }
    return res;
}