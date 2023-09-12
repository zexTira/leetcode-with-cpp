/*//
//  We use an algorithm concerned with modulus to solve this question.
//  With the index of the position for rotation known, we can set the value of another array with same length from pos k to the end, then from the beginnig to k-1, 
      which can be done by (i + k) % n.
//*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }