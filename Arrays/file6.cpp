// Write a program to cyclically rotate an array by one.
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &a)
{
    int n = a.size();
    int i = 0, j = n - 1;
    while (i != j)
    {
        swap(a[i], a[j]);
        i++;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int i;
    rotate(arr);
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}