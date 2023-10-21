/*//
//  We execute BFS in this question.
//  During the BFS process, we count the index of each level, and compute the maximum value of the sum of this level.
//  If the max value is updated at certain level, we also need to record the index of the level. Finally it will be the index of the level with max sum, and we just nedd to return it. 
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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> levelNodeArr;
        levelNodeArr.push_back(root);
        int maxVal = root->val;
        if (!root->left && !root->right)
        {
            return 1;
        }

        int count = 1;
        int result = 1;
        while (levelNodeArr.size() > 0)
        {
            int sum = 0;

            int n = levelNodeArr.size();
            for (int i = 0; i < n; ++i)
            {
                if (levelNodeArr[i]->left)
                {
                    levelNodeArr.push_back(levelNodeArr[i]->left);
                }
                if (levelNodeArr[i]->right)
                {
                    levelNodeArr.push_back(levelNodeArr[i]->right);
                }
            }
            levelNodeArr.erase(levelNodeArr.begin(), levelNodeArr.begin() + n);

            if (levelNodeArr.size() > 0)
            {
                count++;
                for (int i = 0; i < levelNodeArr.size(); ++i)
                {
                    sum += levelNodeArr[i]->val;
                }
                if (maxVal != sum)
                {
                    maxVal = max(maxVal, sum);
                    if (maxVal == sum)
                    {
                        result = count;
                    }
                }
            }
        }
        return result;
    }
};
};