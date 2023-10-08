/*//
//  We consider implementing a stack in this question.
//  Go throughout the string, if it's a letter, push it into the stack, and if it's a star, pop one element up, and what is left in the stack is the final answer.
//  pop all the remaining elements up to a string and reverse the string, it's the final answer.
//  *A simpler way is consider the final string as a stack, when we encounter with a letter push it and when it's a star, just use pop back function.
//*/

class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for (auto i : s)
        {
            if (i != '*')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
            }
        }

        string result;
        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};