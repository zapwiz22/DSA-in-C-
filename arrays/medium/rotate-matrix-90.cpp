#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> &matrix) {
    int n = matrix.size();
    /** rotating the matrix by 90 degrees clockwise is
     * take the transpose of the original matrix
     * reverse every row
     */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "The original matrix is: \n";
    for (auto &vec : arr) {
        for (auto &val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "The rotated matrix is: \n";
    vector<vector<int>> rotated = rotate90(arr);
    for (auto &vec : rotated) {
        for (auto &val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
}