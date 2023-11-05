/*//
//  In this question we traverse the array, sum total gas and total cost in each loop, and check if gas at current position is more than cost, if not we need to start at next position.
//  Finally we just need to compare if total gas is more than total cost, if so we return the start position index, otherwise return -1.
//*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0, total_cost = 0;
        int curr_gas = 0, starting_point = 0;
        for (int i = 0; i < n; i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];
            curr_gas += gas[i] - cost[i];
            if (curr_gas < 0)
            {
                starting_point = i + 1;
                curr_gas = 0;
            }
        }
        return (total_gas < total_cost) ? -1 : starting_point;
    }
};