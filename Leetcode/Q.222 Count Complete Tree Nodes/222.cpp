/*//
//  We use recursion in this question, calculate how many nodes are at the left branch and right branch of each node, and backtracks.
//  And we need to add the node which we call as a parameter in the function, to get the final result. 
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
    int countNodes(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        else
        {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};