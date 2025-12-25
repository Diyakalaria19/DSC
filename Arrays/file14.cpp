// Minimum swaps required bring elements less equal K together
#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k)
{
    int good = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            good += 1;
    }
    int bad = 0, minSwaps = good;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {
            bad += 1;
        }
        if (i == good - 1)
        {
            minSwaps = min(minSwaps, bad);
        }
        else if (i >= good)
        {
            if (arr[i - good] > k)
                bad -= 1;
            minSwaps = min(minSwaps, bad);
        }
    }
    return minSwaps;
}

int main()
{
    int arr1[] = {2, 7, 9, 8, 5, 7, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 5;
    cout << minSwap(arr1, n, k) << "\n";
    return 0;
}