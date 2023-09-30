/*//
//  This question is more related to math. If n has only one digit, it will be happy number if it is 1, and will loop endlessly if it is 4.
//  If n is not 1 or 4, or has more digits, we need to keep calculating the sum of the squares of its digits. After some loops n will be 1 or 4 too.
//  So we check if n==1 as a condition in which we return true, if n==4 return false.
//*/

class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4)
        {
            int sum = 0;
            while (n > 0)
            {
                int temp = n % 10;
                sum += temp * temp;
                n = n / 10;
            }
            n = sum;
        }

        return n == 1;
    }
};