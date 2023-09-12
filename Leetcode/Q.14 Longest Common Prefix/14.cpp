/*//
//  First, sort the strings array in ascending order, then we just need to compare the first and the last string.
//  For these two strings, check each char in corresponding position, if they are not the same, return the final answer.
      Otherwise the result is the same, we need to add it to the final string.
//*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};