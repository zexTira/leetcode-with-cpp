/*//
//  In this question we define some private variables in ths class:
      vector<TreeNode*> inOrderArray : storing all nodes of the tree in in-order traverse order. 
      flag: indicates the index of next element in the node array.
      capacity: indicates the capacity of the node array.
//  When an object is constructed, we call a function to execute the in-order traverse and store all nodes in the nodes array,
      and initialize the flag with value -1 and capacity with the size of array.
//  When calling next() we add 1 to the flag as the next position, and check if flag reaches the end of the array, if so return -1, otherwise return the value
      of the node that flag index indicates.
//  When calling hasNext(), check if flag reaches the end of the array, if so return false, else return true.
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

class BSTIterator {
private:
    vector<TreeNode*> inOrderArray;
    int flag;
    int capacity;

    void InOrderTraverse(TreeNode* root, vector<TreeNode*>& treeArr)
    {
        if (!root)
        {
            return;
        }
        InOrderTraverse(root->left, treeArr);
        treeArr.push_back(root);
        InOrderTraverse(root->right, treeArr);
    }
public:
    BSTIterator(TreeNode* root) {
        flag = -1;
        InOrderTraverse(root, inOrderArray);
        capacity = inOrderArray.size();
    }

    int next() {
        if (flag < capacity)
        {
            ++flag;
            if (flag == capacity)
            {
                return -1;
            }
            else
            {
                return inOrderArray[flag]->val;
            }
        }
        else
        {
            return -1;
        }
    }

    bool hasNext() {
        if (flag < capacity - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};