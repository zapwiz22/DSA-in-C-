#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// using extended boyer moore's voting algorithm to find the atmost two elements which have more than n/3 occurences in the
vector<int> majorityElements(vector<int> &vec) {
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MAX, ele2 = INT_MAX;
    for (int i = 0; i < vec.size(); i++) {
        if (cnt1 == 0) ele1 = vec[i];
        if (cnt2 == 0 && vec[i] != ele1) ele2 = vec[i];
        if (vec[i] == ele1)
            cnt1++;
        else if (vec[i] == ele2)
            cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (auto &val:vec) {
        if (val==ele1) cnt1++;
        else if (val==ele2) cnt2++;
    }
    int mne = (vec.size()/3) + 1;
    vector<int> res;
    if (cnt1>=mne) res.push_back(ele1);
    if (cnt2>=mne) res.push_back(ele2);
    return res;
}

int main() {
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElements(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}