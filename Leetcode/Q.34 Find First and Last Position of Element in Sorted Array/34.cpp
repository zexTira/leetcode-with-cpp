/*//
//  In this quesion we need to do binary search twice to calculate the boundary of result range.
//  First we define a private function which implements conventional binary search algorithm and returns beginning position.
//  Then we do binary search on target and target + 1, and the left boundary can be found by the first search directly. In the second search, we need to substract 1 on the result to confirm the right boundary.
//  Finally we check if the target exists in the array, if so return the range, otherwise return [-1,-1].
//*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size() - 1;
        int startingPosition = lower_bound(nums, beg, end, target);
        int endingPosition = lower_bound(nums, beg, end, target + 1) - 1;

        if (startingPosition < nums.size() && nums[startingPosition] == target)
        {
            return { startingPosition, endingPosition };
        }
        return { -1, -1 };
    }
private:
    int lower_bound(vector<int>& nums, int beg, int end, int target) {
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] < target)
            {
                beg = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return beg;
    }
};