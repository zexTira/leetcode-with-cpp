/*//
//  In this question we first move a pointer and find a subarray with k 0s included, and move another pointer with it as a sliding window.
//  In this sliding window we keep the number of 0s is equal to k as possible, if current count is smaller than k, we only move the first pointer, otherwise we move both pointers to keep the length.
//  When the first pointer reaches the end of array, the length of sliding window is what we desire.
//*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j;
        int count = 0;
        for (j = 0; j < nums.size(); ++j)
        {
            if (nums[j] == 0)
            {
                count++;
            }
            if (count > k)
            {
                if (nums[i] == 0)
                {
                    count--;
                }
                i++;
            }
        }
        return j - i;
    }
};