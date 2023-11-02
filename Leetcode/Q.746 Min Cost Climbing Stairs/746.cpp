/*//
//  In this question we implement a dp array and we traverse from less cost side to more cost side, which is end to beginning.
//  The size of dp array should be 1 more than that of cost, and the first two element should be both 0, because you don't need any cost here to reach the destination.
//  For remaining elements we compare the cost of stepping 2 and 1 units to reach the end and pick the smaller one up, which is a local minimum. 
//  Keep doing this till the end and return the beginning element of dp array.
//*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = min(cost[i] + dp[i + 1], cost[i + 1] + dp[i + 2]);
        }
        return dp[0];
    }
};