/*//
//  In this question we need two pointers, fast and slow.
//  Two pointers should be at the beginning as well, then move fast pointer right, if the value this pointer points to is not zero, give it to the value that slow pointer points to, 
      and move slow pointer right by one, do this loop till fast pointer reaches the end.
//  In this way we can arrange non-zero values from beginning in sequence. Finally we make all values between slow and fast pointer zero, and that's all works done. 
//
//*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return;
        }

        int idx1 = 0, idx2 = 0;
        while (idx2 < n)
        {
            if (nums[idx2] != 0)
            {
                nums[idx1++] = nums[idx2++];
            }
            else
            {
                idx2++;
            }
        }
        while (idx1 < n)
        {
            nums[idx1++] = 0;
        }
        return;
    }
};