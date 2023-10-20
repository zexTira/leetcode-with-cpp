///*
//  We use BFS to solve this question.
//  First we push the value of root into the result, and calculate the average value of nodes in each level, push it into result string.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<double> avg;
        nodes.push_back(root);
        avg.push_back(root->val);

        while (nodes.size() > 0)
        {
            double sum = 0;
            int n = nodes.size();
            for (int i = 0; i < n; ++i)
            {
                if (nodes[i]->left)
                {
                    nodes.push_back(nodes[i]->left);
                }
                if (nodes[i]->right)
                {
                    nodes.push_back(nodes[i]->right);
                }
            }
            nodes.erase(nodes.begin(), nodes.begin() + n);

            if (nodes.size() > 0)
            {
                for (int i = 0; i < nodes.size(); ++i)
                {
                    sum += nodes[i]->val;
                }
                avg.push_back(sum / nodes.size());
            }
        }
        return avg;
    }
};