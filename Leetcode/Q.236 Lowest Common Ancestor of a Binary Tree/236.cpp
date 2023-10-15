/*//
//  We use recursion in this question.  
//  For each node we call this function on its left branch and right branch. If we cannot find p or q in both sides return null, othwise if one of them is not null, we return itself and
     when both nodes are not null, we return its root, then backtracking till the start..
//*/

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
        {
            return NULL;
        }
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode* l;
        TreeNode* r;
        l = lowestCommonAncestor(root->left, p, q);
        r = lowestCommonAncestor(root->right, p, q);
        if (l && r)
        {
            return root;
        }
        if (l)
        {
            return l;
        }
        if (r)
        {
            return r;
        }
        return NULL;
    }
};