/*//
//  We use BFS to solve this question.
//  First we push the value of root into the result vector.
//  For each level we check if the index of the level is even, if so we reverse it after BFS and push it into result array, else we directly do that.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> levelElem;
        vector<vector<int>> result;

        if (!root)
        {
            return result;
        }
        nodes.push_back(root);
        levelElem.push_back(root->val);
        result.push_back(levelElem);

        int count = 1;
        while (nodes.size() > 0)
        {
            int n = nodes.size();
            for (int i = 0; i < n; ++i)
            {
                if (nodes[i]->left)
                {
                    nodes.push_back(nodes[i]->left);
                    levelElem.push_back(nodes[i]->left->val);
                }
                if (nodes[i]->right)
                {
                    nodes.push_back(nodes[i]->right);
                    levelElem.push_back(nodes[i]->right->val);
                }
            }
            nodes.erase(nodes.begin(), nodes.begin() + n);
            levelElem.erase(levelElem.begin(), levelElem.begin() + n);

            if (levelElem.size() > 0)
            {
                if (++count % 2 == 0)
                {
                    reverse(levelElem.begin(), levelElem.end());
                }
                result.push_back(levelElem);
            }
        }
        return result;
    }
};