/*//
// A way similar to two-pointer is implemented in this question
// the first pointer is to go throughout the array and the second pointer is to record different number from given number from the first position.
// Whild using the second pointer, you can just modify the array by give the value in order, instead of erasing the unit of the array
// and the second pointer counts the result as well.
//*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};