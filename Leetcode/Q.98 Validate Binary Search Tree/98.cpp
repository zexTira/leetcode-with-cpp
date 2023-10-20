///*
//  We can inorder traverse the binary search tree according to its feature, and push the value of each node into a vector in this sequence.
//  For this array, if the elements won't follow strictly ascending order, the tree is not a binary search tree either.
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
    vector<int> inorderVec;
    void InorderTraverse(TreeNode* root) {
        if (root)
        {
            InorderTraverse(root->left);
            inorderVec.push_back(root->val);
            InorderTraverse(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        InorderTraverse(root);
        for (int i = 0; i < inorderVec.size() - 1; ++i)
        {
            if (inorderVec[i] >= inorderVec[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};