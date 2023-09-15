/*//
//  In this question, when it comes to some special conditions, just return the corresponding result like when n==0, x==1.
//  And for regular calculation, we need a long long integer to store abs(n), in case the n would be -2^32. when we calculate its absolution and save the result to an int object, overflow will happen.
//  Then, we calculate the pow by two ways to reduce the time complexity, if k is an odd num, we do regular multiply to ans, otherwise we merely do squaring operation to x.
//  And when k==1, x can be multiplied to ans, the loop will be over as well. Finnaly we check if n<0, if so we take its reciprocal as the result.
//*/

class Solution {
public:
    double myPow(double x, int n) {
        long long int k = abs(n);
        double ans = 1.0;
        if (n == 0)
        {
            return 1.0;
        }
        if (x == 1.0)
        {
            return x;
        }
        while (k > 0)
        {
            if (k % 2)
            {
                ans = ans * x;
                k--;
            }
            else
            {
                x = x * x;
                k = k / 2;
            }
        }
        if (n < 0)
        {
            ans = 1 / ans;
        }
        return ans;
    }
};