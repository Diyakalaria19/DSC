// Find the "Kth" max and min element of an array
#include <bits/stdc++.h>
using namespace std;

int kthSmall(vector<int> &arr, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
int main()
{
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    cout << kthSmall(arr, k);
    return 0;
}