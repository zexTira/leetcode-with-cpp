/*//
//  First we let the pivot position index 0 and calculate the sum of numbers which are at left and right side of pivot respectively.
//  Then we move the pivot right, and modify the sum of left and right by adding/substracting one number.
//  If there is a pivot making sum left and right identical, return it, otherwise we continue looping until pivot reaches n-1 position.
//  Then we move the pivot to last position and judge if sum left is 0, if so return the last position, otherwise return -1. 
//*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sumLeft = 0;
        int sumRight = 0;
        for (int i = 1; i < n; ++i)
        {
            sumRight += nums[i];
        }

        int pivot = 0;
        while (pivot < n - 1)
        {
            if (sumLeft == sumRight)
            {
                return pivot;
            }
            else
            {
                sumLeft += nums[pivot++];
                sumRight -= nums[pivot];
            }
        }
        if (sumLeft == 0)
        {
            return n - 1;
        }
        else
        {
            return -1;
        }
    }
};