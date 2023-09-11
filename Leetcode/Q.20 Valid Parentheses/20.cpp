/*//
//  The sa=tack should be used in this question.
//  Basic idea is that we use 3 diffrent numbers to represent 3 kinds of parentheses
//  Then go throughout the array, when it's left part of a parenthese, push the number representing it to the stack, 
      otherwise check if the num at the stack top is representing this parenthese, if yes, pop it out of the stack. Finally check if the stack is empty.
//  One special condition is that the first char is just the right part of a parenthese. We should check if the stack is empty before doing pop in case this happens
//*/


class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        int temp;
        for (auto i : s)
        {
            switch (i)
            {
            case '(':stk.push(1); break;
            case ')':
                if (stk.empty())
                {
                    return false;
                }
                else
                {
                    temp = stk.top();
                    if (temp == 1)
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                break;
            case '[':stk.push(2); break;
            case ']':
                if (stk.empty())
                {
                    return false;
                }
                else
                {
                    temp = stk.top();
                    if (temp == 2)
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                break;
            case '{':stk.push(3); break;
            case '}':
                if (stk.empty())
                {
                    return false;
                }
                else
                {
                    temp = stk.top();
                    if (temp == 3)
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (!stk.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};