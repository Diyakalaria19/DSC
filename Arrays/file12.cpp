// Smallest Subarray with sum greater than a given value
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int smallestSubWithSum(int x, vector<int> &arr)
{
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;

    while (j < arr.size())
    {
        while (j < arr.size() && sum <= x)
        {
            sum += arr[j++];
        }
        if (j == arr.size() && sum <= x)
            break;
        while (i < j && sum - arr[i] > x)
        {
            sum -= arr[i++];
        }
        ans = min(ans, j - i);
        sum -= arr[i];
        i++;
    }
    if (ans == INT_MAX)
        return 0;
    return ans;
}

int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 19};
    int x = 51;
    cout << smallestSubWithSum(x, arr);
    return 0;
}