/*//
//  *This is an interview question provided by amazon
//  To find the smallest number of the substrings in which no repeated chars, we need to make the substrings as long as we can.
//  We used a CharMap in this question to record the repeated char, but maybe a Hash Table is better? Thus I haven't learned that yet.
//  The basic idea is that go throughout the array, and record used chars. To each char, check if it has been appeared before, 
      if so, numcount++, divide substring here and clear the record, do this loop till the end.
//  Be attention that the count will be 1 less than the result, as the loop ends when idx meets the end, so the last count++ won't happen.
//*/

class Solution {
public:
    int partitionString(string s) {
        vector<bool> charMap(128, false);
        int count = 0;
        int strLength = s.size();
        int idx = 0;
        for (int i = 0; i < strLength; i++)
        {
            if (charMap[s[i]] == false)
            {
                charMap[s[i]] = true;
            }
            else
            {
                while (idx != i)
                {
                    charMap[s[idx++]] = false;
                }
                i--;
                count++;
            }
        }
        return count + 1;
    }
};