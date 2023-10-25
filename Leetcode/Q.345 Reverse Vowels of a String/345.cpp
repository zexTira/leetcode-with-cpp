/*//
//  We use two pointers at the beginning and end position of the string.
//  We move these two pointers to the middle of the array, and if one pointer reaches a vowel, stop and continue moving another one until it reaches a vowel too, then swap the letters two pointers point to.
//  After that we move both two pointers to next position and do this until both poiners reach the middle position.
//*/

class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u' ||
            c == 'A' || c == 'O' || c == 'I' || c == 'E' || c == 'U')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void swap(char& a, char& b) {
        char temp;
        temp = a;
        a = b;
        b = temp;
    }
    string reverseVowels(string s) {
        int beg = 0;
        int end = s.size();
        while (beg < end)
        {
            if (isVowel(s[beg]) && isVowel(s[end]))
            {
                swap(s[beg], s[end]);
            }
            else if (isVowel(s[beg]))
            {
                while (!isVowel(s[end]))
                {
                    --end;
                }
                swap(s[beg], s[end]);
            }
            else if (isVowel(s[end]))
            {
                while (!isVowel(s[beg]))
                {
                    ++beg;
                }
                swap(s[beg], s[end]);
            }
            ++beg;
            --end;
        }
        return s;
    }
};