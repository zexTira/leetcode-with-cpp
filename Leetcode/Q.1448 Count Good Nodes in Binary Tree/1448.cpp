/*//
//  In this question we constantly use a current maximum value as a parameter. For each node in the tree, if the element is greater than maximum value, we count it as a result and update the maximum value.
//  Then each node will be compared with the maximum value of all its parent nodes.
//*/

// Definition for a binary tree node.
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
    int ans = 0;
    void solve(TreeNode* root, int currMax) {
        if (!root)
        {
            return;
        }
        if (root->val >= currMax)
        {
            ans++;
            currMax = root->val;
        }
        solve(root->left, currMax);
        solve(root->right, currMax);
    }

    int goodNodes(TreeNode* root) {
        solve(root, INT_MIN);
        return ans;
    }
};