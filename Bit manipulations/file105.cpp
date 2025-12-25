#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int totalSetBits(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += countSetBits(i);
    return total;
}

int main() {
    int n;
    cin >> n;
    cout << totalSetBits(n);
    return 0;
}
