/*//
//  Just implement a conventional sliding window method: first check the result in first sliding window and move the edge right by one each time, then update the result. 
//*/

class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for (int i = 0; i < k; ++i)
        {
            if (isVowel(s[i]))
            {
                count++;
            }
        }
        int maxCount = count;

        int beg = 0;
        int end = k;
        while (end < s.size())
        {
            if (isVowel(s[beg++]))
            {
                count--;
            }
            if (isVowel(s[end++]))
            {
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};