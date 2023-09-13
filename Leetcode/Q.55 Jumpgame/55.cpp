/*//
//  We use a reversed order in this question, move a index from the end of the arrayt forward.
//  The last position that can be reached will be defined at the end of an array, then move the pointer 1 unit forward, check if last position can be reached from this position.
//  If viable, update the last position to this position, otherwise just get into next loop. If finally last position is exactly at the beginning point, suggests a successful jump till the end of 
      the array.
//*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_pos = n - 1;
        for (int i = n - 1; i > -1; i--)
        {
            if (nums[i] + i >= last_pos)
            {
                last_pos = i;
            }
        }
        if (last_pos == 0)
        {
            return true;
        }
        return false;
    }
};