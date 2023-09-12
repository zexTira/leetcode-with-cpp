/*//
//  The basic idea is that compare the first char of array needle of each char in array haystack, if they're the same, compare the remaining char in order. 
//  If all chars are the same, return the index of the first char, and it should be the first time that needle appears in the array haystack as well.
//  *KMP Searching Algorithm also can be implemented in this question to lower the time complexity.
//*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        for (int i = 0; i < n1; i++)
        {
            if (haystack[i] == needle[0])
            {
                for (int j = 0; j < n2 ; j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        break;
                    }
                    if (j == n2 - 1)
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};