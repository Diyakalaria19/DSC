#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long a = abs(dividend);
    long long b = abs(divisor);
    long long res = 0;

    while (a >= b) {
        long long temp = b, mul = 1;
        while (a >= (temp << 1)) {
            temp <<= 1;
            mul <<= 1;
        }
        a -= temp;
        res += mul;
    }
    return sign * res;
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor);
    return 0;
}
