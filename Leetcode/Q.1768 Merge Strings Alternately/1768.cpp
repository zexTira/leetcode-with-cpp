/*//
//  Simply copy and merge.
//*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i, j = 0;
        int m = word1.size();
        int n = word2.size();

        while (i < m && j < n)
        {
            result += word1[i++];
            result += word2[j++];
        }
        if (i == m)
        {
            while (j < n)
            {
                result += word2[j++];
            }
        }
        else
        {
            while (i < m)
            {
                result += word1[i++];
            }
        }

        return result;
    }
};