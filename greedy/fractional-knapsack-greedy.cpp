#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int value;
  int weight;
};

class Solution {
public:
  bool static comp(Item a, Item b) {
    double rate1 = ((double)a.value) / a.weight;
    double rate2 = ((double)b.value) / b.weight;
    return rate1 > rate2;
  }
  double fractionalKnapsack(int W, vector<Item> &vec, int n) {
    sort(vec.begin(), vec.end(), comp);
    double currWeight = 0.0, finalValue = 0.0;
    for (int i = 0; i < n; i++) {
      if (currWeight + vec[i].weight <= W) {
        currWeight += vec[i].weight;
        finalValue += vec[i].value;
      } else {
        int remain = W - currWeight;
        finalValue += (((double)vec[i].value) / vec[i].weight) * (double)remain;
        break;
      }
    }
    return finalValue;
  }
};

int main() {
  int n = 3, weight = 50;
  vector<Item> vec = {{100, 20}, {60, 10}, {120, 30}};
  Solution obj;
  double ans = obj.fractionalKnapsack(weight, vec, n);
  cout << "The maximum value is " << setprecision(2) << fixed << ans;
  return 0;
}
