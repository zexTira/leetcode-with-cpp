/*//
//  First we check if amount is smaller than 1, if so we don't need any coins so return 0.
//  Else we define a minimum dp array with size being amount+1, and set mindp[0] 0 following the rule above, and set other elements maximum integer,
//  Then for each element from mindp[1], we check if there's a coin in coins which meets mindp[i-coin] is updated before, which is not max integer (but we need to make sure i-coin > 0)
//  If there are multiple coins meet the requirement we need to seek the minimum number, so we compare them and pick the minimum one up.
//  Finally we check if mindp[amount], if it's still maximum integer, return -1. Otherwise return its value. 
//*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1)
        {
            return 0;
        }

        vector<int> mindp(amount + 1, INT_MAX);
        mindp[0] = 0;
        for (int i = 1; i < mindp.size(); ++i)
        {
            for (auto j : coins)
            {
                if (i - j >= 0 && mindp[i - j] != INT_MAX)
                {
                    mindp[i] = min(mindp[i], mindp[i - j] + 1);
                }
            }
        }
        if (mindp[amount] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return mindp[amount];
        }
    }
};