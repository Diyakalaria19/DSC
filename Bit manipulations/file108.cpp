#include <bits/stdc++.h>
using namespace std;

int square(int n) {
    int res = 0;
    int times = abs(n);
    while (times--) {
        res += abs(n);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << square(n);
    return 0;
}
