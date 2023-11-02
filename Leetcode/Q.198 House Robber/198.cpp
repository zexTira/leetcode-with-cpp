/*//
//  in this question we define a dp array whose size is equal to nums to store the local maximum at each case.
//  If there's only one house, what we get is nums[0], just return it.
//  Otherwise we can get nums[0] in the firt house or nums[1] in the second house at most, and for remaining elements, what we can get is either the maximum value from its left neighbor,
     or the sum of maximum value from all of the elements which is at left of its left neighbor and itself. Compare and pick the greater one as the value of this postion.
//  Continue doing this until we got all local maximum values, sort the array after that and return the last element, which is the global maximum value.
//*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else
        {
            vector<int> maxdp(nums.size(), 0);
            maxdp[0] = nums[0];
            maxdp[1] = nums[1];

            for (int i = 2; i < maxdp.size(); ++i)
            {
                int maxVal = maxdp[0] + nums[i];
                for (int j = 0; j <= i - 2; ++j)
                {
                    maxVal = max(maxdp[j] + nums[i], maxVal);
                }
                maxdp[i] = max(maxVal, maxdp[i - 1]);
            }
            sort(maxdp.begin(), maxdp.end());
            return *(maxdp.end() - 1);
        }
    }
};