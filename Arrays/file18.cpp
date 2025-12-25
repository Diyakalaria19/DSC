// Maximum profit by buying and selling a share atmost twice
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;
    vector<vector<int>> curr(3, vector<int>(2, 0));
    vector<vector<int>> next(3, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int k = 1; k <= 2; k++)
        {
            curr[k][1] = max(-prices[i] + next[k][0], next[k][1]);
            curr[k][0] = max(prices[i] + next[k - 1][1], next[k][0]);
        }
        next = curr;
    }
    return curr[2][1];
}

int mxProfit(vector<int> prices)
{
    int firstBuy = INT_MIN;
    int firstSell = 0;
    int secondBuy = INT_MIN;
    int secondSell = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        firstBuy = max(firstBuy, -prices[i]);
        firstSell = max(firstSell, firstBuy + prices[i]);
        secondBuy = max(secondBuy, firstSell - prices[i]);
        secondSell = max(secondSell, secondBuy + prices[i]);
    }
    return secondSell;
}
int main()
{
    vector<int> price = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(price) << endl;
    cout << mxProfit(price);
    return 0;
}