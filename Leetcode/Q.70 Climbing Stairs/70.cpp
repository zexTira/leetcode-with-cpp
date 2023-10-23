/*//
//  We implement a dp array in this question.
//  For each element in this array, we set the first two elements 1 and 2, representing the ways to climb 1 or 2 stairs respectively.
//  For remaining elements, we compute the ways by adding two previous elements together.
//  Finally we just need to return the nth element.
//*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else
        {
            int* arr = new int[n];
            arr[0] = 1;
            arr[1] = 2;
            for (int i = 2; i < n; ++i)
            {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
            int result = arr[n - 1];
            delete[] arr;
            return result;
        }
    }
};