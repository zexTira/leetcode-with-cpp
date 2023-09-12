/*//
//  The question requires a pointer at both side of the array, and move to the middle.
//  As is known to us, the volume of water is decided by the bound of smaller height.
//  Therefore, our idea is that keep comparing the height of both bound, to find which one is shorter, then move its pointer to next position,
      and keep recording the maximum volume.
//  Finally the result will be the maximum volume we recorded.
//*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int idx0 = 0;
        int idx1 = height.size() - 1;
        int maxResult = 0;
        while (idx0 < idx1)
        {
            maxResult = max(maxResult, (idx1 - idx0) * min(height[idx0], height[idx1]));
            if (height[idx0] < height[idx1])
            {
                idx0++;
            }
            else
            {
                idx1--;
            }
        }
        return maxResult;
    }
};