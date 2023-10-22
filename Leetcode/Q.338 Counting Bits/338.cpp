/*//
//  For each number smaller or equal to n, count its 1 bits by constantly doing modulus and division with 2, when th result reaches 0, how many 1s after doing modulus is the result of this number.
//*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++)
        {
            int a = i;
            int count = 0;
            while (a > 0)
            {
                if (a % 2 == 1)
                {
                    count++;
                }
                a /= 2;
            }
            result.push_back(count);
        }
        return result;
    }
};