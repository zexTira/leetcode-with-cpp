/*//
//  First we push the new interval into basic intervals array, and then sort it.
//  For each vector in the intervals, we initially push the first element into the ans array, then compare if its first number is bigger than the second number of the last element in ans array. If so, push it into ans array.
//  If not we just need to modify the second number of the last element in the ans array in case of overlapping, and substitute it with a larger one between the second num of both.
//*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        if (n == 0)
        {
            return { newInterval };
        }

        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            int x = ans.size() - 1;
            if (ans[x][1] >= intervals[i][0])
            {
                ans[x][1] = max(ans[x][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};