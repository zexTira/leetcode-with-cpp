/*//
//  First we should locate the elements in preorder from left to right in inorder sequence as a root, when we locate one of them, split from that position and it will be the left part for left branch
      and right part for right branch.
//  We continue searching process and recursely do it on left and right part then, until it reaches the end.
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
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int& Idx, int left, int right) {
        if (left > right)
        {
            return NULL;
        }
        int pivot = left;
        while (inorder[pivot] != preorder[Idx])
        {
            pivot++;
        }
        Idx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = construct(preorder, inorder, Idx, left, pivot - 1);
        newNode->right = construct(preorder, inorder, Idx, pivot + 1, right);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int Idx = 0;
        return construct(preorder, inorder, Idx, 0, n - 1);
    }
};