/*//
//  In this question we need to go throughout the array from both sides to mid to find the the highest num of left part and right part of this array.
//  For those whose height is smaller than current lmax/rmax, if lmax<=rmax, which means the shorter one is lmax, we should add the difference between maxvalue and current height to result. 
//*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n - 1];
        int lpos = 1;
        int rpos = n - 2;
        int ans = 0;
        while (lpos <= rpos)
        {
            if (height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if (height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if (lmax <= rmax)
            {
                ans += lmax - height[lpos];
                lpos++;
            }
            else
            {
                ans += rmax - height[rpos];
                rpos--;
            }

        }
        return ans;
    }
};