/*//
//  In this question we first sort the array in ascending order to easier get the sum from two sides.
//  Next we define two pointers at the beginning and end respectively, if the sum of numbers that two pointers point to are equal to k, the count should increase
     by 1, and move two pointers towards mid by one unit.
//  Else if the sum is bigger than k, which means the right number is too big, we move right pointer to left by one unit and compare again.
     Otherwise the left number is too small, we move left pointer to right by one unit.
//  While the left pointer meets its right counterpart, stop the loop and return the count as a result.
//*/


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        while (left < right)
        {
            if (nums[left] + nums[right] == k)
            {
                count++;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return count;
    }
};