/*//
//  *This is an interview question provided by Amazon.
//  First we need to find all factors of the given number n using modulus, and time complexity is O(n)
//  Push n's all factors into an array
//  Check if the kth num does exist in this array, if so returns the kth factor of n, otherwise returns -1, representing k>array.size()
//*/

class Solution {
public:
    int kthFactor(int n, int k) {
        vector <int> factorArr;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                factorArr.push_back(i);
            }
        }
        if (k > factorArr.size())
        {
            return -1;
        }
        else
        {
            return factorArr[k - 1];
        }
    }
};