/*//
//  In this question we use greedy algorithm.
//  First we sort the interval array and set defult result to 0, then if there's only one element in the array we can just return it.
//  Then we check all elements, and find if two adjacent elements are overlapping, if so add 1 to the answer and get into next loop.
//*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), tmp = intervals[0][1], ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (tmp > intervals[i][0])
            {
                ans++;
                tmp = min(tmp, intervals[i][1]);
            }
            else
            {
                tmp = intervals[i][1];
            }
        }
        return ans;
    }
};