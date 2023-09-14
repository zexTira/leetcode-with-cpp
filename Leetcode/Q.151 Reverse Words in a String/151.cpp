/*//
// Stack and stringstream are used in this question.
//  Stringstream is used for recording the whole string with each word seperated, while stack is used for storing these words and pop reversedly.  
//  Using result to receive the words from stringstream and push them into the stack, and then pop them to the result.
//  *Be attention that no need to add a space after last pop operation.
//*/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> temp;
        string result;
        stringstream ss(s);
        while (ss >> result)
        {
            temp.push(result);
        }
        result = "";
        while (!temp.empty())
        {
            result += temp.top();
            if (temp.size() != 1)
            {
                result += " ";
            }
            temp.pop();
        }
        return result;
    }
};