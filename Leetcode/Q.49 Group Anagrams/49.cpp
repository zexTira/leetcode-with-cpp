/*//
//  First for each string in strs vector, we sort the characters in this string.
//  Then we use sorted string as a key, push the original string into the vector that the key corresponds with in an unordered map.
//  Finally, go throughout each key in the unordered map and output its corresponding string vector as the result.
//*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> vocMap;
        vector<vector<string>> ans;
        for (auto i : strs)
        {
            string s = i;
            sort(s.begin(), s.end());
            vocMap[s].push_back(i);
        }

        for (auto i : vocMap)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};