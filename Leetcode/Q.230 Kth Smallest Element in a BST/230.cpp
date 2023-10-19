/*//
//  In this question the object that we manipulate is a binary search tree.
//  So when we traverse the tree in in-order, the elements will be sorted from small to big.
//  In this way we just need to do the traverse and return rhe kth element of in-order sequence.
//*/

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderVec;
    void InorderTraverse(TreeNode* root, int k) {
        if (root)
        {
            InorderTraverse(root->left, k);
            inorderVec.push_back(root->val);
            InorderTraverse(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        InorderTraverse(root, k);
        return inorderVec[k - 1];
    }
};