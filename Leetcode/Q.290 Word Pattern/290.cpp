/*//
//  We need two hashmap to record the relationship between a character and corresponding string, as a pair is strictly biunique.
//  First we use a stringstream object to read the original string, then output it into a temp string to split the string into words by space.
//  Next we push each word to a vector, then we build the bilateral relation between character and word in one pair.
//  For each pair, if the relation does not exist yet, we record it in both unordered map from character to string and from string to character. 
//  Then if the relation has been built, we check if this relation is biunique by finding the char and string in each map, if it is return true, otherwise return false.
//*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        istringstream is(s);
        string temp;
        while (is >> temp)
        {
            str.push_back(temp);
        }
        if (pattern.size() != str.size())
        {
            return false;
        }

        int n = str.size();
        unordered_map<char, string> umap1;
        unordered_map<string, char> umap2;

        for (int i = 0; i < n; ++i)
        {
            if (umap1[pattern[i]] == "")
            {
                if (umap2.find(str[i]) == umap2.end())
                {
                    umap1[pattern[i]] = str[i];
                    umap2[str[i]] = pattern[i];
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (umap1[pattern[i]] != str[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};