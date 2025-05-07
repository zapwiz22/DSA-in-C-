#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &vec) {
    int n = vec.size();
    int m = vec[0].size();
    int col0 = 1;
    // checking which need to be marked zero
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (vec[i][j] == 0) {
                vec[i][0] = 0;
                if (j==0) col0 = 0;
                else vec[0][j]=0;
            }
        }
    }
    // marking zeroes except the first row and first column
    for (int i=1;i<n;i++) {
        for (int j=1;j<m;j++) {
            if (vec[i][j] != 0) {
                if (vec[i][0]==0 || vec[0][j]==0) vec[i][j]=0;
            }
        }
    }
    // marking the first row as zero
    if (vec[0][0]==0) {
        for (int j=0;j<m;j++) vec[0][j]=0;
    }
    if (col0==0) {
        for (int i=0;i<n;i++) vec[i][0]=0;
    }
    return vec;
}

int main() {
    vector<vector<int>> vec1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << "The original matrix is: \n";
    for (auto &vec:vec1) {
        for (auto &val:vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "The new matrix now is: \n";
    vector<vector<int>> ans = zeroMatrix(vec1);
    for (auto &vec:ans) {
        for (auto &val:vec) {
            cout << val << " ";
        }
        cout << endl;
    }
}