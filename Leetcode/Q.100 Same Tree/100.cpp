///*
//  Recursion is used in this question since the feature of binary tree.
//  If both trees are empty, return true, otherwise if one tree is empty while another one isn't or the value of corresponding nodes are not identical, return false.
//  Recurse on the left and right child of each node and compare the corresponding node in another tree, until reaches the leaf.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL || p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};