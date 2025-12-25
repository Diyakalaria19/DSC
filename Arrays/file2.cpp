// Find the maximum and minimum element in an array
#include <iostream>
#include <limits.h>
using namespace std;

int min(int a[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}
int max(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main()
{
    int n;
    cout << "enter the size:";
    cin >> n;
    int a[n];
    cout << "enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Maximum:" << max(a, n) << " Minimum:" << min(a, n);
    return 0;
}