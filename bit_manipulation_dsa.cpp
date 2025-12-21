//9 questions

#include <bits/stdc++.h>
using namespace std;

// 1. Count Set Bits in an Integer
int countSetBits(int n) {
    int count = 0;
    while(n > 0) {
        if(n &1){
             count++;
        }
        n = n >> 1;
    }
    return count;
}

// 2. Check if Number is Power of Two
bool isPowerOfTwo(int n) {
    if(n <= 0){
         return false;
    }
    return (n & (n -1)) == 0;
}

// 3. Find Position of Only Set Bit
int findPosition(int n) {
    if(n == 0|| (n & (n -1))!= 0){
        return -1;
    }
    int pos = 1;
    while((n & 1) == 0) {
        n = n>>1;
        pos++;
    }
    return pos;
}

// 4. Count Bits to Flip A to B
int countBitsFlip(int a, int b) {
    int x = a^b;
    int count = 0;
    while(x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

// // 5. Find Two Non-Repeating Elements
// vector<int> twoNonRepeating(vector<int>& arr) {
//     int xorr = 0;
//     for(int x : arr) xorr ^= x;

//     int setBit = xorr & -xorr; // rightmost set bit
//     int num1 = 0, num2 = 0;

//     for(int x : arr) {
//         if(x & setBit) num1 ^= x;
//         else num2 ^= x;
//     }

//     return {num1, num2};
// }

// 6. Total Set Bits from 1 to N (Simple)
int totalSetBits(int n) {
    int count=0;
    for(int i=1; i<=n;i++) {
        count= count+ countSetBits(i);
    }
    return count;
}

// 7. Copy Set Bits in a Range
int copySetBits(int x, int y, int l, int r) {
    for(int i = l; i <= r; i++) {
        int mask = 1 << (i - 1);
        if(y & mask)
            x = x | mask;
    }
    return x;
}

// 8. Divide Two Integers Without *, /, %
int divide(int dividend, int divisor) {
    int sign = ((dividend<0)^(divisor<0)) ? -1 : 1;
    long long a = abs(dividend);
    long long b = abs(divisor);
    long long res = 0;

    while(a >= b) {
        long long temp = b, mul = 1;
        while(a >= (temp << 1)) {
            temp <<= 1;
            mul <<= 1;
        }
        a -= temp;
        res += mul;
    }
    return sign * res;
}

// 9. Square of a Number Without *, /
int square(int n) {
    int res = 0;
    int times = abs(n);
    while(times--){
        res += abs(n);
    } 
    return res;
}

// 10. Check if a Number has Only One Set Bit
bool hasOnlyOneSetBit(int n) {
    if(n == 0){
         return false;
    }
    return (n & (n - 1)) == 0;
}
