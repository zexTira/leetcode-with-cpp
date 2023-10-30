/*//
//  In this question we go throughout the array and when it is 0, count how many 1s are at its left and right side within the bound of edge of array or 0 and find the max one.
//  If the elements in the array are all 1, return size-1, else return the max count.
//*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int n = nums.size();
        bool sign = false;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
            {
                left = i;
                right = i;
                while (left > 0)
                {
                    left--;
                    if (nums[left] == 0)
                    {
                        left++;
                        break;
                    }
                }
                while (right < n - 1)
                {
                    right++;
                    if (nums[right] == 0)
                    {
                        right--;
                        break;
                    }
                }
                sign = true;
                maxLength = max(right - left, maxLength);
            }
        }

        if (sign)
        {
            return maxLength;
        }
        else
        {
            return n - 1;
        }
    }
};