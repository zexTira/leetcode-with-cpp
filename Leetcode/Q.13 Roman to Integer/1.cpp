/*//
//  The Hashmap also can be implemented to solve the problem.
//  Go throughout the array, check if the char is V/L/D/M, if so directly add corresponding num to the result.
//  For char I/X/C, we need to check the following number, in some cases mentioned in the question, we need to subtract a number instead of adding it.
//  Moreover, when checking special cases, we need to ensure that the index is not larger than size of the array to prevent overflowing.
//*/

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case 'I':
                if ((i + 1) <= n)
                {
                    if (s[i + 1] == 'V' || s[i + 1] == 'X')
                    {
                        result -= 1;
                    }
                    else
                    {
                        result += 1;
                    }
                }
                break;
            case 'V':result += 5; break;
            case 'X':
                if ((i + 1) <= n)
                {
                    if (s[i + 1] == 'L' || s[i + 1] == 'C')
                    {
                        result -= 10;
                    }
                    else
                    {
                        result += 10;
                    }
                }
                break;
            case 'L':result += 50; break;
            case 'C':
                if ((i + 1) <= n)
                {
                    if (s[i + 1] == 'D' || s[i + 1] == 'M')
                    {
                        result -= 100;
                    }
                    else
                    {
                        result += 100;
                    }
                }
                break;
            case 'D':result += 500; break;
            case 'M':result += 1000; break;
            }
        }
        return result;
    }
};