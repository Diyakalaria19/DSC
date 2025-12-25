// reverse the an array
#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - 1 - i]);
    }
}
int main()
{
    int n;
    cout << "enter the size:";
    cin >> n;
    cout << "enter the elements:\n";
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int vl;
        cin >> vl;
        arr.push_back(vl);
    }
    reverse(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}