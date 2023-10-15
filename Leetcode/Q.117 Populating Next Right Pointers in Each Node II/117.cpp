///*
//  In this question we first implement a BFS way to get all elements in an array in preorder sequence.
// Then all we need to do is cut the connection of root node and linking these nodes to the right branch node by node from root.
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
    void preorder(TreeNode* root, vector<int>& ans)
    {
        if (root == NULL)
        {
            return;
        }
        ans.push_back(root->val);
        if (root->left)
        {
            preorder(root->left, ans);
        }
        if (root->right)
        {
            preorder(root->right, ans);
        }
    }

    void flatten(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }

        vector<int> ans;
        preorder(root, ans);

        root->left = nullptr;
        root->right = nullptr;
        TreeNode* currPtr = root;
        for (int i = 1; i < ans.size(); ++i)
        {
            TreeNode* newNodePtr = new TreeNode(ans[i]);
            currPtr->right = newNodePtr;
            currPtr = currPtr->right;
        }
    }
};