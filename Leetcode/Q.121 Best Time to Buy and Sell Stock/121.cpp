/*//
//  The way to get this question done is that keep finding the minimal point of stock value, and looking for a point to get maximum profit.
//*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = prices[0];

        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return maxProfit;
    }
};