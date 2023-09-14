/*//
//  Is this question we only need to consider left half part of the number
//  Especially, when x<0, it definitely cannot be a palindrome, return false.
//  Moreover, if x is a multiple of 10, it cannot be calculated in this algorithm, and we know that it cannot be a palindrome either, so return false as well.
//  To remaining nums, what we do is move the last digit of x to the first digit of reversed, until reversed>=x, by two sentences in while.
//  Finally we compare if reversed num is equal to x after division, in the case that the digit number of original x is an even number.
//  Or reversed/10==x, in the case that the digit number of original x is an odd number.
//*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }
        int reversed = 0;
        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (x == reversed) || (x == reversed / 10);
    }
};