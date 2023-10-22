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
    int getMaxAns(TreeNode* root, int& max_ans) {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            max_ans = max(max_ans, root->val);
            return root->val;
        }
        int leftAns = getMaxAns(root->left, max_ans);
        int rightAns = getMaxAns(root->right, max_ans);
        max_ans = max(max_ans, max(root->val, max(leftAns, max(rightAns, leftAns + rightAns)) + root->val));
        return max(root->val, max(leftAns, rightAns) + root->val);
    }

    int maxPathSum(TreeNode* root) {
        int max_ans = INT_MIN;
        getMaxAns(root, max_ans);
        return max_ans;
    }
};