/*//
//  *You should use hash table in this question instead of IntMap, otherwise the map will occupy tons of memory size.
//  Two-pointer idea is used in this algorithm, check if a number occurs more than twice, if so don't record it, just move another pointer forward
//  The range of the number is [-10000, 10000], so we need a map whose size is 20001 to meet the requirement.
//  Finally, those number occuring more than twice will be kicked out of the array.
//*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> IntMap(20001, 0);
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            nums[i] += 10000;
            if (IntMap[nums[i]] < 2)
            {
                IntMap[nums[i]]++;
                nums[i] -= 10000;
                nums[count++] = nums[i];
            }
            else
            {
                continue;
            }
        }
        return count;
    }
};