/*//
//  In this question we need 2 hashmaps to get things done, with each recording how many times a number occurs in the array1 and array2 respectively.
//  Then go throughout two arrays again, if we can not find the element in the hashmap for the counterpart, it will be a potential answer. 
      if the element occurs more than once, we substract by 1 of its count in the hashmap of its array. and when the count becomes zero, we push it into result vector to avoid duplicates.
//  For array2 the measure is fairly the same. After that we push two result vectors to the final result matrix.
//*/


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap1;
        unordered_map<int, int> umap2;
        for (const auto& i : nums1)
        {
            umap1[i]++;
        }
        for (const auto& i : nums2)
        {
            umap2[i]++;
        }

        vector<int> result1;
        vector<int> result2;
        for (const auto& i : nums1)
        {
            if (umap2.find(i) == umap2.end())
            {
                umap1[i]--;
                if (umap1[i] == 0)
                {
                    result1.push_back(i);
                }
            }
        }
        for (const auto& i : nums2)
        {
            if (umap1.find(i) == umap2.end())
            {
                umap2[i]--;
                if (umap2[i] == 0)
                {
                    result2.push_back(i);
                }
            }
        }
        return { result1,result2 };
    }