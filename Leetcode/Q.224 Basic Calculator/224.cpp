/*//
//  In this question we need to deal with negative sign and parthedrones carefully.
//  We first initialize a stack stroring current calculate result and current sign, and if we meet a  number, convert it to long long type using mathematical algorithm, and mutiply current sign as a result, 
      then reset the sign to positive.
//  If we meet a left parenthese, it's time to push current result into the stack, along with current sign, and reset result to calculate lacal result within the parentheses.
//  If we meet a right parenthese, we need to check the sign in the top element of the stack and multiply it, and add local result to the previous result we stored.
//  If the character is a '-', the sign should be mutiplied (-1) to alter to the opposite side. Do these until reaches the end of string.

//*/

class Solution {
public:
    int calculate(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int, int>> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                long long int num = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if (s[i] == '(')
            {
                st.push({ sum, sign });
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                sum = st.top().first + (st.top().second * sum);
                st.pop();

            }
            else if (s[i] == '-')
            {
                sign = -1 * sign;
            }
        }
        return sum;
    }
};