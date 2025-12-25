#include <bits/stdc++.h>
using namespace std;

int copySetBits(int x, int y, int l, int r) {
    for (int i = l; i <= r; i++) {
        int mask = 1 << (i - 1);
        if (y & mask)
            x |= mask;
    }
    return x;
}

int main() {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    cout << copySetBits(x, y, l, r);
    return 0;
}
