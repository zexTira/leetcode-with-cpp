/*//
//  The idea and algorithm implemented here is almost the same as that in Q.383, so it's unnecessary to describe it again,  just refer to Q.383.
//*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> umap;
        for (auto i : s)
        {
            ++umap[i];
        }
        for (auto j : t)
        {
            if (umap.find(j) == umap.end() || umap[j] <= 0)
            {
                return false;
            }
            --umap[j];
        }
        return true;
    }
};