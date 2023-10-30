/*//
//  In this question we use the feature of BST to find the key element, if the key is greater than root, search in the right subtree, else seaech in the left subtree.
//  When we find the node with key element, we first check if it's leaf node, if so just return nullptr representing node deleted.
//  If the node has exactly one child, we move its child to current position.
//  Finally if the node has two childs, we constantly search the right child of its left child until reaches the leaf node, this is the value just smaller than current node, and make the value of current node
      the value of leaf node. Then we just need to execute this function again to delete that leaf node.
//*/

// Definition for a binary tree node.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root)
        {
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {
                if (!root->left && !root->right)
                {
                    return NULL;
                }
                if (!root->left || !root->right)
                {
                    return root->left ? root->left : root->right;
                }

                TreeNode* temp = root->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
};