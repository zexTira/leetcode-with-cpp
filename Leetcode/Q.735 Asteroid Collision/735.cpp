/*//
//  In this question we need a stack to complete the job.
//  There would be four cases for two consequent number: both negative or positive, first negative and second positive or opposite. We just need to consider the fourth case, as the collision will happen.
//  In other 3 cases, we just need to push the value into the stack, but in that special case we need to compare the absolute value of the top element in this stack and current element,
//  If current value is bigger than the top element, pop the top element from the stack and compare the next top element, continue the loop and if the stack becomes empty or the top element is negative, 
      push current value to the stack, and when two values are identical, just pop the value and finish this loop, make current value next position.
//  Finally all remaining elements will be i stack in the sequence from bottom to the top, so we need to pop them one by one into result array and reverse that array.
//*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (auto it = asteroids.cbegin(); it != asteroids.cend(); ++it)
        {
            if (!stk.empty() && *it < 0 && stk.top()>0)
            {
                while (!stk.empty() && stk.top() > 0 && -(*it) > stk.top())
                {
                    stk.pop();
                }

                if (!stk.empty())
                {
                    if (-(*it) == stk.top())
                    {
                        stk.pop();
                    }
                    else if (stk.top() < 0)
                    {
                        stk.push(*it);
                    }
                }
                else
                {
                    stk.push(*it);
                }
            }
            else
            {
                stk.push(*it);
            }

        }

        vector<int> result;
        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};