///*
//  Recursion is used in this question since the feature of binary tree.
//  We implement a recursion function to manipulate every node of the tree, if a node is an empty node just pass through, otherwise we need to swap its left and right child.
//  Then we call the same function on its two childs to start the recursion until reaches the leaf node.
//  In our main (not literal "main" function in C++) function, we record the pointer of root node and call this function on it, finally return that root node pointer.
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
    void recursion(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        else
        {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            recursion(root->left);
            recursion(root->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* ans = root;
        recursion(root);
        return ans;
    }
};