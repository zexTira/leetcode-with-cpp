/*//
//  In this question we first compare if the result of str1+str2 and str2+str1 is the same, only so they can own a common divisor.
//  If they are the same return the substring with length being equal to the greatest common divisor of any one of two strings, from beginning. 
//*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return str1 + str2 != str2 + str1 ? "" : str1.substr(0, gcd(str1.size(), str2.size()));
    }
};