/*//
//  A simple DP way to solve this Fibonacci-based question.
//*/

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 1;
        }
        else
        {
            int* dpArr = new int[n + 1];
            dpArr[0] = 0;
            dpArr[1] = 1;
            dpArr[2] = 1;
            for (int i = 3; i <= n; ++i)
            {
                dpArr[i] = dpArr[i - 1] + dpArr[i - 2] + dpArr[i - 3];
            }
            int result = dpArr[n];
            delete[] dpArr;
            return result;
        }
    }
};