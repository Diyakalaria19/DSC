#include <bits/stdc++.h>
using namespace std;

bool hasOnlyOneSetBit(int n) {
    if (n == 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    int n;
    cin >> n;
    cout << hasOnlyOneSetBit(n);
    return 0;
}

