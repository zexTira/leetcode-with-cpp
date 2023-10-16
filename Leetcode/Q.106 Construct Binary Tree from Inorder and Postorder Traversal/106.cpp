/*//
//  The solution is quite similar to that of Q.105, but we need to notice that the root index should be initially the last element of postorder array,
      and we need to move this index to the left during the recursion.
//  Moreover we need to construce the right branch first, because we can only find the index in the right part of inorder sequence first.
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
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int& Idx, int left, int right) {
        if (left > right)
        {
            return NULL;
        }

        int pivot = left;
        while (inorder[pivot] != postorder[Idx])
        {
            pivot++;
        }
        Idx--;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->right = construct(inorder, postorder, Idx, pivot + 1, right);
        newNode->left = construct(inorder, postorder, Idx, left, pivot - 1);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int Idx = n - 1;
        return construct(inorder, postorder, Idx, 0, n - 1);
    }
};