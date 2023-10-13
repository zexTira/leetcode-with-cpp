///*
//  Recursion is used in this question since the feature of binary tree.
//  We first check if is an empty tree, then check if one of the child branch is null but another is not.
//  Then for each node we check if its two child nodes are equal and four child nodes of these two are symmetric following the rules.
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        if (!left && !right)
        {
            return true;
        }
        if (!left || !right)
        {
            return false;
        }
        return (left->val == right->val) && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
    }
};