/*//
//  *This solution is not an all-passed solution, with only one case not accepting due to time exceed, but it is my extreme to push the solution here, and it's indeed a universal manner.
//  The basic idea is defining two unordered maps, with one storing the number that one word occurs in words array, and another one counting the number of each word in sliding window. 
//  The size of sliding window should be words.size()*words[0].size(), we count the words in this sliding window and check if it's equal to the map correspoing to the words array. If so return current index,
      otherwise reset the counting map and continue the loop until the end.
//  In this question we also implement a trick, which can be described as when one word in sliding window isn't equal to anyone in words array, we can stright forward jump to next loop as this string in sliding window
     will definitely not meet the requirement.
//*/

class Solution {
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int m = words.size();
        int n = words[0].size();
        int k = 0;
        string temp;
        int count = 0;
        bool nextLoopSignal = false;
        unordered_map<string, int> umap;
        unordered_map<string, int> judge;

        for (int i = 0; i < words.size(); ++i)
        {
            ++umap[words[i]];
        }

        for (int i = 0, j = m * n - 1; j < s.size(); ++i, ++j)
        {
            k = i;
            while (k <= j)
            {
                temp += s[k++];
                if ((k - i) % n == 0)
                {
                    for (count = 0; count < m; ++count)
                    {
                        if (temp == words[count])
                        {
                            judge[words[count]]++;
                            break;
                        }
                    }
                    temp = "";
                    if (count == m)
                    {
                        nextLoopSignal = true;
                        count = 0;
                        break;
                    }
                }
            }
            if (nextLoopSignal == true)
            {
                for (int a = 0; a < m; ++a)
                {
                    judge[words[a]] = 0;
                }
                nextLoopSignal = false;
                continue;
            }
            for (int a = 0; a < m; ++a)
            {
                if (judge[words[a]] != umap[words[a]])
                {
                    break;
                }
                if (a == m - 1)
                {
                    result.push_back(i);
                }
            }
            for (int a = 0; a < m; ++a)
            {
                judge[words[a]] = 0;
            }
        }
        return result;
    }
};