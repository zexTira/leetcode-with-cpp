/*//
//  In this question we need a set to store numbers in the nums array.
//  After that, we need to find the beginning of one sequence, and then count how many numbers are in this sequence, and record the max count.
//  Finally return the final max count.
//*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int i : nums)
        {
            set.insert(i);
        }

        int maxCount = 0;
        for (int i : nums)
        {
            if (set.find(i - 1) == set.end())
            {
                int currentNum = i;
                int count = 1;
                while (set.find(currentNum + 1) != set.end())
                {
                    currentNum++;
                    count++;
                }
                maxCount = max(count, maxCount);
            }
        }
        return maxCount;
    }
};