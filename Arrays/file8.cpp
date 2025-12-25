// find Largest sum contiguous Subarray [V. IMP]
#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(vector<int> &arr)
{
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        maxEnding = max(arr[i], maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}
int main()
{
    int n;
    cout << "enter the size";
    cin >> n;
    vector<int> res;
    cout << "enter the elements";
    for (int i = 0; i < n; i++)
    {
        int vl;
        cin >> vl;
        res.push_back(vl);
    }
    cout << "Max sum of subArray:" << maxSubArraySum(res);
    return 0;
}