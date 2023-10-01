/*//
//  In this question we will operate two iterators of string s, a left one and a right one.
//  For both iterators we define it as the beginning of the string s, next we move the right one until its dereferencing content is a space.
//  Then we copy every character between two iterators to a temp string, and reverse it. Then add it to result string, with one more space.
//  After that we move both iterators to the next position and do the loop until right one reaches the end of string s. 
//*/

class Solution {
public:
    string reverseWords(string s) {
        auto lptr = s.begin();
        auto rptr = s.begin();
        string res = "";
        string temp = res;

        while (rptr != s.end())
        {
            if (*rptr != ' ')
            {
                rptr++;
                continue;
            }
            else
            {
                for (auto it = lptr; it != rptr; ++it)
                {
                    temp += *it;
                }
                reverse(temp.begin(), temp.end());
                res += temp;
                res += " ";
                temp = "";
                rptr = lptr = rptr + 1;
            }
        }

        for (auto it = lptr; it != rptr; ++it)
        {
            temp += *it;
        }
        reverse(temp.begin(), temp.end());
        res += temp;
        return res;
    }
};