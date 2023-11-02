/*//
//  In this question we implement a monotomic stack.
//*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mstk;
        int n = temperatures.size();
        vector<int> result(n, 0);
        mstk.push(make_pair(0, temperatures[0]));

        for (int i = 1; i < temperatures.size(); ++i)
        {
            while (!mstk.empty() && temperatures[i] > mstk.top().second)
            {
                result[mstk.top().first] = i - mstk.top().first;
                mstk.pop();
            }
            mstk.push(make_pair(i, temperatures[i]));
        }

        return result;
    }
};