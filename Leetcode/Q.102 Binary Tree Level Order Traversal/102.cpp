///*
//  In this question we only need to implement a way to do BFS and push the result of each value to the vector, the measure is same as that in Q.117.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> levelSequence;
        vector<int> levelValSequence;
        vector<vector<int>> result;
        if (root)
        {
            levelSequence.push_back(root);
            levelValSequence.push_back(root->val);
            result.push_back(levelValSequence);
        }
        else
        {
            return result;
        }

        while (levelSequence.size() != 0)
        {
            int n = levelSequence.size();
            for (int i = 0; i < n; i++)
            {
                if (levelSequence[i]->left != NULL)
                {
                    levelSequence.push_back(levelSequence[i]->left);
                    levelValSequence.push_back(levelSequence[i]->left->val);
                }
                if (levelSequence[i]->right != NULL)
                {
                    levelSequence.push_back(levelSequence[i]->right);
                    levelValSequence.push_back(levelSequence[i]->right->val);
                }
            }
            levelValSequence.erase(levelValSequence.begin(), levelValSequence.begin() + n);
            levelSequence.erase(levelSequence.begin(), levelSequence.begin() + n);
            if (levelSequence.size() != 0)
            {
                result.push_back(levelValSequence);
            }

        }
        return result;
    }
};