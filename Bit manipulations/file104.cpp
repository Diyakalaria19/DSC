#include <bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b) {
    int x = a ^ b;
    int count = 0;
    while (x) {
        count += (x & 1);
        x >>= 1;
    }
    return count;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << countBitsFlip(a, b);
    return 0;
}
