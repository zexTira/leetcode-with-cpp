/*//
//  For the num n we continuously divide it by 4 until it is smaller than 4.
//  If the remaining number is 1, it's power of 4, else not.
//*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        while (n >= 4)
        {
            if (n % 4 != 0)
            {
                return false;
            }
            n /= 4;
        }

        if (n == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};