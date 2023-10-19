/*//
//  In this question the object that we manipulate is a binary search tree.
//  So when we traverse the tree in in-order, the elements will be sorted from small to big.
//  In this way we just need to do traversing and compute the absolute difference of every pair of adjacent elements in in-order sequence and return the minimum one.  
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
    vector<int> inorder_vector;
    void inorderTraversal(TreeNode* root) {
        if (root)
        {
            inorderTraversal(root->left);
            inorder_vector.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        int min_diff = INT_MAX;
        for (int i = 1; i < inorder_vector.size(); i++)
        {
            min_diff = min(min_diff, inorder_vector[i] - inorder_vector[i - 1]);
        }
        return min_diff;
    }
};