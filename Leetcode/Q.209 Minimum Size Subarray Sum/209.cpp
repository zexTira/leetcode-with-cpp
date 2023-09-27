/*//
//
//*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int l = 0, r = 0;
        int sum = 0;
        while (r < n)
        {
            sum += nums[r];
            while (sum >= target)
            {
                if (sum >= target)
                {
                    res = min(res, r - l + 1);
                    sum -= nums[l++];
                }
            }
            ++r;
        }
        if (res == INT_MAX)
        {
            return 0;
        }
        return res;
    }
};