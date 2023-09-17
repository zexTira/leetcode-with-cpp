/*//
//  This is a brutal way to solve this question so not recommended, the better solution should be involved with binary search.
//  In this solution, we just need to find a factor i from zero to a number whose square is just bigger than x, if we got it, just decrease the i by one, it is the final result.
//  *Notice that in this solution overflow on int range may happen, so the i and result both should be the long long int type.
//*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
        {
            return x;
        }

        long long int res;
        long long int i = 1;
        while (res <= x)
        {
            i++;
            res = i * i;
        }
        return i - 1;
    }
};