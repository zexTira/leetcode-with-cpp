/*//
//  The key point in this question is how to manipulate the carry.
//  We calculate the carry by the sum of each corresponding bit in two arrays.  If the sum is smaller than 2, the result will be the same and no more jobs, just add it to the result array.
//  If the sum is larger than 2, we need to take carry into consideration.  This bit of the result will be sum%2, and the carry should be sum/2, and do the loop till the end.
//  Finally, reverse the result array.
//*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
            {
                carry += a[i--] - '0';
            }
            if (j >= 0)
            {
                carry += b[j--] - '0';
            }
            ans += carry % 2 + '0';
            carry /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};