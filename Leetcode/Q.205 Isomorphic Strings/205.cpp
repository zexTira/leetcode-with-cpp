/*//
//  We need two hashmap to record the relationship between a character and corresponding character, as a pair is strictly biunique.
//  First we check if the size of two strings are identical, if not return false directly.
//  Next, For each pair, if the relation does not exist yet, we record it in both unordered map from first to second character and from second to first character.
//  Then if the relation has been built, we check if this relation is biunique by finding the first char and second char as each key in each map, if it is return true, otherwise return false.
//*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, char> umap1;
        unordered_map<char, char> umap2;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (umap1.find(s[i]) == umap1.end())
            {
                if (umap2.find(t[i]) == umap2.end())
                {
                    umap1[s[i]] = t[i];
                    umap2[t[i]] = s[i];
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (umap1[s[i]] != t[i])
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }
        }
        return true;
    }