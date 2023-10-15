/*//
//  Just apply conventional binary search.
//*/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int num = n / 2;
        int left = 1;
        int right = n;
        int currentResult = guess(num);
        while (currentResult != 0)
        {
            currentResult = guess(num);
            if (currentResult == -1)
            {
                right = num - 1;
                num = left + (right - left) / 2;
            }
            else if (currentResult == 1)
            {
                left = num + 1;
                num = left + (right - left) / 2;
            }
            else
            {
                continue;
            }
        }
        return num;
    }
};