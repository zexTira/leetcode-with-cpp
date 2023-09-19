/*//
//  *Notice that the solution is viable on both Question 136 & 137.
//  First we sort the nums array to better distinguish the num we'd like to find by checking if there's at least one number on its both sides equal to it, 
//  Next, check if the first number is unique or size of the array is merely 1, if so, return it.
//  Then, check remaining numbers in this array until reach the second last num.
//  If we still can not find that num, it will be definitely the last number, return it.
//*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto i = nums.begin();
        if (i == nums.end() - 1 || *(i + 1) != *i)
        {
            return *i;
        }
        for (++i; i != nums.end() - 2; ++i)
        {
            if (*(i - 1) != *i && *(i + 1) != *i)
            {
                return *i;
            }
        }
        ++i;
        return *i;
    }
};