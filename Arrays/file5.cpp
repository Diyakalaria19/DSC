// Move all negative numbers to beginning and positive to end with constant extra space
#include <bits/stdc++.h>
using namespace std;

vector<int> move(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}
// using two-pointer
vector<int> move1(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        while (left < right && arr[left] < 0)
            left++;
        while (right > left && arr[right] > 0)
            right--;
        if (right > left)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return arr;
}
int main()
{
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    vector<int> ans = move(arr);
    vector<int> ans1 = move1(arr);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}