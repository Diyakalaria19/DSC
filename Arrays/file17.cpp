// Median of 2 sorted arrays of different size
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

double medianOf2(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    if (n > m)
        return medianOf2(b, a);
    int lo = 0, hi = n;
    while (lo <= hi)
    {
        int mid1 = (lo + hi) / 2;
        int mid2 = (n + m + 1) / 2 - mid1;

        int l1 = (mid1 == 0 ? INT_MIN : [mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : b[mid2]);
    }
}