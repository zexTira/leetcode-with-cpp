/*//
//  In this question we need a sign to know current node is a ledt child or right child during recursion.
//  If current node is a left child, we reset the count on its left subtree, and add 1 to the count on its left subtree, vice versa on right child.
//  In each recursion we compare the result to get the max one.
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

    void CountNodes(TreeNode* root, int dis, string sign) {
        if (!root)
        {
            return;
        }
        ans = max(ans, dis);
        if (sign == "left")
        {
            CountNodes(root->right, 1, "left");
            CountNodes(root->left, dis + 1, "right");
        }
        else
        {
            CountNodes(root->left, 1, "right");
            CountNodes(root->right, dis + 1, "left");
        }
    }

    int longestZigZag(TreeNode* root) {
        CountNodes(root, 0, "left");
        CountNodes(root, 0, "right");
        return ans;
    }
};