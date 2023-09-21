/*//
//  In this question we first check if one number is 0 or the bit count of two numbers are not identical, in these cases the result will be 0.
//  Otherwise we do bit and to every number in the arrat to get the result.
//*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0 || right == 0)
        {
            return 0;
        }
        if ((int)log2(left) != (int)log2(right))
        {
            return 0;
        }

        int res = left;
        while (left < right)
        {
            res &= ++left;
        }
        return res;
    }
};