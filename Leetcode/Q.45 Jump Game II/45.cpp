/*//
//  In this question we define a minimum dp array.
//  If the nums array has only 1 element, just return 0.
//  Otherwise we set the first value of dp array 0 and others maximum integer, and traverse the array, find if there's a previous value meets the requirement that the distance of its position and current positon
      is smaller than or equal to its value. If so we check its corresponding position in dp array, and choose the smaller one between this value plus 1 and current value for the value of current position in dp array.
//  After that we just need to return the nth element in minimum dp array.
//*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }

        vector<int> mindp(n, INT_MAX);
        mindp[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (i - j <= nums[j])
                {
                    mindp[i] = min(mindp[i], mindp[j] + 1);
                }
            }
        }
        return mindp[n - 1];
    }
};