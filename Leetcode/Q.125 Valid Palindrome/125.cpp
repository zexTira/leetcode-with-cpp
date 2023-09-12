/*//
//  The question also requires the usage of two-pointer, each from begining and end;
//  Go throghout the array from both sides to the middle, if there's a char except for num and letter, just neglect it, move the index to the nect position.
//  If meeting a valid char, we  should check if both chars are the same. In terms of a letter, we need to convert it to lower letter.
// If two chars are not the same, just return false. When two pointers meet at the mid-point, represeting that the string is palindrome.
// *Be attention that we use some fuctions defined in stdlib,  bool isalnum(char) check if the char is num or letter, char tolower(char) converts an upper letter to lower one.
//*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};