#include <bits/stdc++.h>
using namespace std;

int findPosition(int n) {
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    int pos = 1;
    while ((n & 1) == 0) {
        n >>= 1;
        pos++;
    }
    return pos;
}

int main() {
    int n;
    cin >> n;
    cout << findPosition(n);
    return 0;
}
