/*//
//  In this questions there are two kinds of operation in the token: nums and operators.
//  We need a stack to store the nums when going throughout the token array, and when it comes to operators, do corresponding operation on top two nums in the stack.
//  That is how things can be easily done, push the numbers into the stack in order, when it's an operator, pop up two numbers from the stack and do calculation, then push the result back into the stack,
      till the end of the token array. Finally return the sole element in this stack.
//  *Notice that for those numbers we need to do type conversion from string to int.
//*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        int tmp1, tmp2, tmpres;

        for (auto i : tokens)
        {
            if (i == "+" || i == "-" || i == "*" || i == "/")
            {
                tmp1 = result.top();
                result.pop();
                tmp2 = result.top();
                result.pop();

                if (i == "+")
                {
                    tmpres = tmp2 + tmp1;
                }
                else if (i == "-")
                {
                    tmpres = tmp2 - tmp1;
                }
                else if (i == "*")
                {
                    tmpres = tmp2 * tmp1;
                }
                else
                {
                    tmpres = tmp2 / tmp1;
                }
                result.push(tmpres);
            }
            else
            {
                result.push(stoi(i));
            }
        }
        return result.top();
    }
};