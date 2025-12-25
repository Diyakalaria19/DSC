// Find whether an array is a subset of another array
#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> &a, vector<int> &b)
{
    multiset<int> hashSet(a.begin(), a.end());

    for (int num : b)
    {
        if (hashSet.find(num) == hashSet.end())
        {
            return false;
        }
        hashSet.erase(hashSet.find(num));
    }
    return true;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> b = {1, 2, 3, 1};

    if (isSubset(a, b))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    return 0;
}