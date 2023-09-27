/*//
//  In this quesion we just need to implement conventional binary search algorithm.
//  For array who has only one element, we compare it to the target and confirm the insert position if the sole element is not equal to the target.
//  Otherwise we do binary search, and still use the same comparing method if we cannot find the target, then finally return the position index. 
//*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 1)
        {
            if (target <= nums[0])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        int beg = 0;
        int end = nums.size() - 1;
        int mid = beg + (end - beg) / 2;
        while (beg < end)
        {
            if (nums[beg] == target)
            {
                return beg;
            }
            else if (nums[end] == target)
            {
                return end;
            }
            else
            {
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                    mid = beg + (end - beg) / 2;
                }
                else
                {
                    beg = mid + 1;
                    mid = beg + (end - beg) / 2;
                }
            }
        }

        if (target < nums[mid])
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
};