/*//
//  In this question, there are two seperated phases whcih are input phase and output phase.
//  In the input stage, we are ought to define a stack and a temp string to record fine name. Just go throughout the path and if we encounter with '/', neglect it. In this way we can save the contents between
     those '/'s in temp string.
//  There are 3 situations for the temp string, if temp is a valid file name, we need to push this string into the stack, and if it's a ".", all we gonna do is continuing the loop, 
      and if it's "..", we are ought to pop one element from the stack if the stack is not empty, and this is the end of input stage.
//  During output stage we add each string in the stack to our path in the order in which elements pop up, and add '/' between each element. Moreover if the stack is empty we merely need to return "/".
//*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;

        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
            {
                continue;
            }

            string temp;
            while (i < path.size() && path[i] != '/')
            {
                temp += path[i];
                ++i;
            }

            if (temp == ".")
            {
                continue;
            }
            else if (temp == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(temp);
            }
        }

        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        if (res.size() == 0)
        {
            return "/";
        }
        return res;
    }
};