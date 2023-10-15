///*
//  In this question we implement a BFS way to solve it.
//  For every node, we push its left and right node to an array in sequence to get the nodes in same layer, and in this layer, we set the next pointer of each node points to the nnode at next position in the array.
//  In terms of the last node in the array, set its next pointer a null pointer.
//  Then erase all elements in this array and get to the next layer, until reaches the leaves of the tree. 
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
    Node* connect(Node* root) {
        vector<Node*> arr;
        arr.push_back(root);
        if (root == NULL)
        {
            return root;
        }
        while (arr.size() != 0)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (i == arr.size() - 1)
                {
                    arr[i]->next = NULL;
                }
                else
                {
                    arr[i]->next = arr[i + 1];
                }
            }

            int n = arr.size();
            for (int i = 0; i < n; i++)
            {
                if (arr[i]->left != NULL)
                {
                    arr.push_back(arr[i]->left);
                }
                if (arr[i]->right != NULL)
                {
                    arr.push_back(arr[i]->right);
                }
            }
            arr.erase(arr.begin(), arr.begin() + n);
        }
        return root;
    }
};