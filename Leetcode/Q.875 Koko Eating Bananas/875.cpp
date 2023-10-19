/*//
//  In this question we need a solution in a binary search way.
//  The max speed of eating should be the largest element in this array, which takes hours of size of array to eat all bananas, and min speed should certainly be 1.
//  Then we calculate the mid speed and start conventional binary search. Calculate the time with mid speed to eat all bananas and compare with h,
      when the min speed reaches the max speed, the current mid speed is what we are looking for.
//  *Notice that we can not break the loop when mid speed is equal to h because there are some cases in which it's not the min speed, as we lost some accuracy when calculating integer time. 
      And the speed should be in long long type in case of overflow.
//*/

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int maxSpeed = *max_element(piles.begin(), piles.end());
        long long int minSpeed = 1;
        long long int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;

        long long int time;
        while (minSpeed <= maxSpeed)
        {
            time = 0;
            for (int i = 0; i < piles.size(); ++i)
            {
                if (piles[i] % midSpeed == 0)
                {
                    time += piles[i] / midSpeed;
                }
                else
                {
                    time += piles[i] / midSpeed + 1;
                }
            }
            if (time <= h)
            {
                maxSpeed = midSpeed - 1;
            }
            else if (time > h)
            {
                minSpeed = midSpeed + 1;
            }
            midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
        }
        return midSpeed;
    }
};