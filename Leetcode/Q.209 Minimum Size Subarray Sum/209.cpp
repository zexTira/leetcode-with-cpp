/*//
//  In this question we need two pointers as a sliding window to get things done.
//  First we define the minimal length as the maximum integer, and move the right pointer, if the sum of numbers in this window reaches the target, 
      record this length if it's shorter than the current length.
//  Then we move the left pointer until the sum in this window smaller than the target, and move right pointer again.
//  When right pointer reaches the end of the array, return final length value. If the length is still its initial value return 0.
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