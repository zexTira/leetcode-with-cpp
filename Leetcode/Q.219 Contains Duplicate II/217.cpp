/*//
//  We use an unordered map whose key is an int to record nums in the array and value an int vector to record corresponding occuring position.
//  If the element occurs for the first time, push its position into the vector.
//  Otherwise we need to push its position into the vector and compare it with the last position when it occurs at, since it requires the minimum distance.
//  If the diffrence between two positions is equal to or smaller than k, return true, and return false if all positions do not meet the requirement.
//*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (umap.find(nums[i]) == umap.end())
            {
                umap[nums[i]].push_back(i);
            }
            else
            {
                umap[nums[i]].push_back(i);
                if (abs(umap[nums[i]][umap[nums[i]].size() - 1] -
                    umap[nums[i]][umap[nums[i]].size() - 2]) <= k)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
        }
        return false;
    }
};