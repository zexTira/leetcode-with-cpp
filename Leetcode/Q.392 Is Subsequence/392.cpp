/*//
//  Two-pointer should be used to solve this question.
//  Two pointers should point the first element of each array. Go throughout the array s, if s[i]=t[j], which means a char in array t appears in array s, move the pointer of array t to next position.
//  Finally, check if pointer of array t reaches the final position, if so, all chars in array t appear in array s, in which case we should return true.
//*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx0 = 0;
        int idx1 = 0;
        int n1 = s.size();
        int n2 = t.size();

        while (idx0 < n1 && idx1 < n2)
        {
            if (s[idx0] == t[idx1])
            {
                idx0++;
            }
            idx1++;
        }
        if (idx0 == n1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};