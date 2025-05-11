#include <cmath>
#include <iostream>
using namespace std;

void swapBitwise(int &a, int &b) {  // swap using bitwise operators
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return;
}

bool checkSetbit(int n, int pos) {
    return (n & (1 << pos));
}

bool checkOdd(int n) {
    return (n & 1);  // true if odd else false
}

bool checkPowerOf2(int n) {
    return !(n & (n - 1));
}

int clearBit(int n, int i) {  // clear the ith bit
    return (n & (~(1 << i)));
}

int toggleBit(int n, int i) {  // toggle the ith bit
    return (n ^ (1 << i));
}

int removeLastSetBit(int n) {
    return (n & (n - 1));
}

int countSetBits(int n) {
    int length = log2(n) + 1;
    int cnt = 0;
    for (int i = 0; i < length; i++) {
        cnt += ((n & (1 << i))?1:0);
    }
    return cnt;
}

int main() {
    // swap 2 variables without using third variable and using bitwise operators
    int a = 2, b = 3;
    cout << "initially, a: " << a << " b: " << b << endl;
    swapBitwise(a, b);
    cout << "finally, a: " << a << " b: " << b << endl;

    // check if the ith bit is set or not
    int c = 13;                          // 1 1 0 1
    cout << checkSetbit(13, 2) << endl;  // should come true
    cout << checkSetbit(13, 1) << endl;  // should come false

    // check if the number is odd or not
    cout << checkOdd(13) << endl;
    cout << checkOdd(12) << endl;

    // check if number is a power of 2 or not
    cout << checkPowerOf2(64) << endl;
    cout << checkPowerOf2(23) << endl;

    // clear the ith bit
    cout << clearBit(13, 2) << endl;

    // toggle the ith bit
    cout << toggleBit(13, 1) << endl;

    // remove the last set bit
    cout << removeLastSetBit(40) << endl;

    // count the number of setbits
    cout << countSetBits(13) << endl;
    return 0;
}