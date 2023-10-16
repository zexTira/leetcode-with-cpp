///*
//  We can exploit a feature in this question to solve it, which can be described as the leaf nodes form the same sequence while in one preorder traverse if they are leaf-similar.
//  So all we need to do is push the leaf nodes of two trees in sequence into two arrays respectively, check if all the elements in corresponding position is identical, if so return true, otherwise false.
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
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            ans.push_back(root->val);
        }
        if (root->left)
        {
            preorder(root->left, ans);
        }
        if (root->right)
        {
            preorder(root->right, ans);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        preorder(root1, arr1);
        preorder(root2, arr2);

        if (arr1.size() != arr2.size())
        {
            return false;
        }
        for (int i = 0; i < arr1.size(); ++i)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }
};