/*//
//  In this question we need to implement a recursion way to solve it.
//  We follow the rule of binary search tree, if the value is smaller than current value, we search in its left branch, else search in the right branch.
//  If we find that node with the vaule being equal to the k, we just return it.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* result;
        if (!root)
        {
            return nullptr;
        }

        if (val < root->val)
        {
            result = searchBST(root->left, val);
        }
        else if (val > root->val)
        {
            result = searchBST(root->right, val);
        }
        else
        {
            result = root;
        }
        return result;
    }
};