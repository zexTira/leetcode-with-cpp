/*//
//  In this question, when tree numbers are all non-zero, we fetch their last bits by doing bit-and with 1, that would mask all previous numbers of the last bit.
//  Next we need to figure out how many steps are required to flip 1 to 0, and add the number of steps to the result.
//  Then we right move three numbers (divided by 2) to throw out current last bit and do the loop until three numbers all become 0.
//  Finally return the result.
//*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a || b || c)
        {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            if (bitC == 0)
            {
                if (bitA == 1 && bitB == 1)
                {
                    ans += 2;
                }
                else if (bitA || bitB)
                {
                    ans += 1;
                }
            }
            else if (bitC == 1 && bitA == 0 && bitB == 0)
            {
                ans += 1;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};