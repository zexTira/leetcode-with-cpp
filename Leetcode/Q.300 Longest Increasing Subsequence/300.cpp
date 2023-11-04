/*//
//  In this question we define a maximum dp array.
//  If the nums array has only 1 element, just return 1.
//  Otherwise we set the first value of dp array 1, and traverse the array, find if current element is greater than a previous element, if so wo pick the element with maximum value in dp array and 
      add 1 to the value, put it into current position.
//  After that we sort the dp array, find the maximum value(the last one) and return it.
//*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return 1;
        }

        vector<int> maxdp(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    maxdp[i] = max(maxdp[i], maxdp[j] + 1);
                }
            }
        }
        sort(maxdp.begin(), maxdp.end());
        return maxdp[n - 1];
    }
};