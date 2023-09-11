/*//
// In this question, you just need to sort the array by ascend order.
// In this way, the majority element will occupy half or more than half spaces od this array absolutely.
//So just return the num at the mid point, it will be the result.
//*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};