/*//
//  Just go throughout the whole array, check if there are two nums whose sum is the target.
//  If result cannot be found in the end, returns an empty array.
//  Else returns the result array.
//  Time complexity:O(n^2)
//  Maybe two pointers can be implemented to the question? Check it later. 
//*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i,j };
                }
            }
        }
        return {};
    }
};