/*//
//  In this question we use greedy algorithm to get the solution.
//  If there's only one element in prices array, directly return 0, otherwise we define a max dp array.
//  Set the first max value in the array 0, and for remaining elements, we just need to compare with the previous one max value, as we can get the most optimized result in every step.
//  Judge if profit of two days is greater than 0, if so we add the profit to the max value last day, and set current max value the result.
//  After traversing the array, the max profit would be the last element of the max dp array.
//*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
        {
            return 0;
        }

        vector<int> maxdp(n, 0);
        for (int i = 1; i < n; ++i)
        {
            maxdp[i] = max(maxdp[i - 1], maxdp[i - 1] + (prices[i] - prices[i - 1]));
        }
        return maxdp[n - 1];
    }
};