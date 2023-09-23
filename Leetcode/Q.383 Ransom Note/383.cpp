/*//
//  We use unordered map to implement a hash table to solve this question.
//  First, establish a refelction between charcters and the count which records how many times this character occurs in this array.
//  For each chars in magazine, record its count.
//  Then for each char in ransom note, if we cannot find it in the map or it occurs more than recorded count for this char, return false, else return true.
//*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (auto c : magazine)
        {
            m[c]++;
        }
        for (auto c : ransomNote)
        {
            if (m.find(c) == m.end() || m[c] <= 0)
            {
                return false;
            }
            m[c]--;
        }
        return true;
    }
};