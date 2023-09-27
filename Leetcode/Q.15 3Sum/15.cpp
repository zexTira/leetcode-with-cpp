/*//
//  In this question the key is the basic rule on how to locate 3 numbers.
//  First we sort the array and set one pointer from the beginning to the end as loop condition, and remaining two pointers respectively on the second position and the end position.
//  While two pointers keeping current left-right position relationship, if 3 sum is larger than target, we need to reduce the num by move the right pointer the the left by 1 unit, otherwise we move the left pointer.
//  If we find the sum result being equal to the target, push 3 nums as an integral to the set, otherwise continue till i reaches the end of the array.
//  Finally we just need to return the result in the set in the form of matrix.
//*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    s.insert({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        for (auto triplets : s)
        {
            output.push_back(triplets);
        }
        return output;
    }
};