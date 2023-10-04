/*//
//  *This is a viable algorithm but with time exceeding in last 15% cases. However it reaches where I can push to extremely.
//  In this question we need two unordered maps to record how many times each character in string t and sliding window occurs respectively.
//  The minimum length of sliding window would be the length of t, and for each char in sliding window, record them and check if every item is larger than
      item with corresponding key, if so return the string in sliding window, otherwise move the window to the next. 
//  If the sliding window reaches the end, we add the length of sliding window by 1 and reset it to initial place and do the same thing. 
     If the sliding window length reaches the length of string s, which means all else fails, return an empty string.
//  Notice that if the size of string s is smaller than that of string t at the beginning, we straight forward return an empty string.
//*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
        {
            return "";
        }

        unordered_map<char, int> umap1;
        unordered_map<char, int> umap2;
        unordered_map<char, int> initumap;
        for (auto it = t.cbegin(); it != t.cend(); ++it)
        {
            umap1[*it]++;
        }

        int n = s.size();
        int m = t.size();
        int windowLen = m;
        int beg = 0;
        int end = beg + windowLen - 1;
        int count = 0;
        string result;
        while (windowLen++ <= n)
        {
            for (beg = beg, end = end; end < n; ++beg, ++end)
            {
                int ptr = beg;
                while (ptr <= end)
                {
                    umap2[s[ptr++]]++;
                }
                for (count = 0; count < m; ++count)
                {
                    if (umap1[t[count]] <= umap2[t[count]])
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                umap2 = initumap;

                if (count == m)
                {
                    for (int i = beg; i <= end; ++i)
                    {
                        result += s[i];
                    }
                    return result;
                }
            }
            beg = 0;
            end = beg + windowLen - 1;
        }
        return "";
    }
};