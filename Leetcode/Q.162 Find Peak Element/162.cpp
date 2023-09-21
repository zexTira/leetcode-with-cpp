/*//
//  We use classic binary search in this question.
//  First if the size of the array is equal to 1, the sole elemrnt will be the peak, return it.
//  If size of the array is larger than 1, we need two pointers at the beginning and end position of the array to indicate the searching range, and another pointer k to indicate the median of range.
//  Then we check if k position is a peak, if so return position k, else we need to compare its both neighbors, if its left neighbor is bigger than it, which means peak will be at its left side.
      In this case we shrink the seraching range to the left area, recalculate the median and do loop.  if its right neighbor is bigger than it all we need to do is same except shrinking the seraching range 
      to the right area.
//  When right-left=1 and we still cannot locate the peak, the peak will definitely be either nums[i] or nums[j], just return the index of the bigger one.
//*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }

        int i = 0;
        int j = nums.size() - 1;
        int k = i + (j - i) / 2;

        while (1)
        {
            if (k != i && k != j)
            {
                if (nums[k - 1] < nums[k] && nums[k + 1] < nums[k])
                {
                    return k;
                }
                else if (nums[k - 1] > nums[k])
                {
                    j = k;
                    k = i + (j - i) / 2;
                }
                else
                {
                    i = k;
                    k = i + (j - i) / 2;
                }
            }
            else
            {
                return nums[i] > nums[j] ? i : j;
            }
        }
    }
};