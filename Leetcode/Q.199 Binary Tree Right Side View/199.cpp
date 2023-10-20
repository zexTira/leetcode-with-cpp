///*
//  We use BFS to solve this question.
//  For each level we push the nodes into a vector in sequence and return the value of last node in this vector. 
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root)
        {
            return result;
        }

        vector<TreeNode*> nodes;
        nodes.push_back(root);
        result.push_back(root->val);

        while (nodes.size() > 0)
        {
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
                auto it = nodes.end() - 1;
                result.push_back((*it)->val);
            }

        }
        return result;
    }
};