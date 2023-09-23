/*//
//  In this quesion there are two conditions which are split by the postion at which rotates the array. 
//  We still define the beginning, end and mid postion as conventional binary search algoriithm goes. If the rotating position is after mid, which means nums[low] <= nums[mid],
      in this case if target is in the left part, we rest the pointers to do binary search in this part, otherwise do it on the other part.
//  Another condition is similar, which is that rotating position is before mid, so we just need to do opposite operations from previous condition.
//  If we can find the target, return pos, otherwise return -1;
//*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target) 
            {
                return mid;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};