/*//
//  In this question we define two queues and push the parts seperated by '.' of each version number into them.
//  We store each part as a string, when it comes to '.', convert it to integer and reset the string, then go to the next part.
//  After all elements being pushed into queue, we compare the front elements of two queue, and return if one is bigger than another. If two elements are equal, pop them and compare the next two.
//  If all elements are equal, when one queue goes empty, there may be some elements remaining in another queue, we compare them with 0 and confirm the result.
//*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> v1;
        queue<int> v2;
        int ptr = 0;
        string result = "";
        int intResult;

        while (ptr != version1.size())
        {
            result += version1[ptr++];
            if (version1[ptr] == '.')
            {
                ptr++;
                intResult = stoi(result);
                v1.push(intResult);
                result = "";
            }
        }
        intResult = stoi(result);
        v1.push(intResult);

        result = "";
        ptr = 0;
        while (ptr < version2.size())
        {
            result += version2[ptr++];
            if (version2[ptr] == '.')
            {
                ptr++;
                intResult = stoi(result);
                v2.push(intResult);
                result = "";
            }
        }
        intResult = stoi(result);
        v2.push(intResult);

        while (!v1.empty() && !v2.empty())
        {
            if (v1.front() < v2.front())
            {
                return -1;
            }
            else if (v1.front() > v2.front())
            {
                return 1;
            }
            else
            {
                v1.pop();
                v2.pop();
            }
        }
        if (v1.empty())
        {
            while (!v2.empty())
            {
                if (v2.front() > 0)
                {
                    return -1;
                }
                else
                {
                    v2.pop();
                }
            }
        }
        else
        {
            while (!v1.empty())
            {
                if (v1.front() > 0)
                {
                    return 1;
                }
                else
                {
                    v1.pop();
                }
            }
        }
        return 0;
    }
};