/*//
//  In this question we can find a universal principle, which is when the given num n is increasing, when it equals to a num which is multiple of 5, trailing zeroes in result will be increased by 1.
//  And so on, when it meets a num which is multiple of 25(5^2), 125(5^3), etc. trailing zeroes will be increased by 1 as well.
//  In this way we just need to calculate the number of "factors related to 5" which are smaller or equal to given number n.
//*/

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (int i = 5; n / i >= 1; i *= 5)
        {
            count += n / i;
        }
        return count;
    }
};