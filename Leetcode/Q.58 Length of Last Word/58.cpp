/*//
//  The question requires a pointer at the end of the array, and move forward
//  First we check where the first valid leeter is, by jumping through those non-letter chars like space or something similar.
//  When we encounter with the first letter, the counting process should start, then when we meet another non-letter char or at the bound of this array, the loop should be ended.
//  Finally, return the count, as it's exactly the result.
//*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.size() - 1;
        int count = 0;
        while (!isalpha(s[idx]))
        {
            idx--;
        }
        while (idx >= 0 && isalpha(s[idx]))
        {
            count++;
            idx--;
        }
        return count;
    }
};