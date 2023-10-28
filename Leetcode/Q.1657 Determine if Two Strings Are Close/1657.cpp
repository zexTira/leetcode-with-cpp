/*//
//  For these two words first we need to compare if their length is equal, and if all existing elements included are the same.
//  Then we use hashmaps to record the occurance counts of each element, and push them into a vector then sort. If two vectors are exactly identical, return true. 
//*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
        {
            return false;
        }
        if (set(word1.begin(), word1.end()) != set(word2.begin(), word2.end()))
        {
            return false;
        }

        unordered_map<char, int> umap1;
        unordered_map<char, int> umap2;
        for (int i = 0; i < word1.size(); ++i)
        {
            umap1[word1[i]]++;
            umap2[word2[i]]++;
        }

        vector<int> nums1;
        vector<int> nums2;
        for (auto it = umap1.begin(); it != umap1.end(); ++it)
        {
            nums1.push_back(it->second);
        }
        sort(nums1.begin(), nums1.end());
        for (auto it = umap2.begin(); it != umap2.end(); ++it)
        {
            nums2.push_back(it->second);
        }
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < nums1.size(); ++i)
        {
            if (nums1[i] != nums2[i])
            {
                return false;
            }
        }
        return true;
    }
};