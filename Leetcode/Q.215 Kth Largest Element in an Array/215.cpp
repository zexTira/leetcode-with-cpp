/*//
//  In this question we convert the input vector to a heap, and keep popping the biggest element for k-1 times, after that the biggest element still in the vector is the element we desire. 
//*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        for (int i = 1; i < k; ++i)
        {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};