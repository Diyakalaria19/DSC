// Minimise the maximum difference between heights [V.IMP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMinDiff(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int res = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0)
            continue;
        int minH = min(arr[0] + k, arr[i] - k);
        int maxH = max(arr[i - 1] + k, arr[n - 1] - k);
        res = min(res, maxH - minH);
    }
    return res;
}
int main()
{
    int k = 2;
    vector<int> arr = {1, 5, 8, 10};
    cout << "MinDiff:" << getMinDiff(arr, k);
    return 0;
}