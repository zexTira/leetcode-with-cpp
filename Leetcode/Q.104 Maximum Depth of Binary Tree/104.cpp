///*
//  Recursion is used in this question since the feature of binary tree.
//  If root is an empty node just return 0, otherwise we check all its left child and right child using the same function with number of layer plus one each time.
//  Iterate until the function call reaches the leaf of the tree, and backtracking will start, return the bigger one of left and right child for each code until the root.
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
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        else
        {
            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
        }
    }
};