/*//
//  In this question we define an unordered map to record the num and its corresponding occuring times.
//  If a num occurs less than twice we simply add its count.
//  Otherwise we just need to return true. If no numbers  occurs more than once return false.
//*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (auto i : nums)
        {
            if (umap[i] < 1)
            {
                umap[i]++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};