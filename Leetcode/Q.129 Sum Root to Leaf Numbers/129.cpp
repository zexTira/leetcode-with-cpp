/*//
//  In this question we use recursion to solve it.
//  In every node, we calculate current value by passing a parameter continuously, which is the value of root, when it experience recursion each time, we
     consider it as a param and pass it to the next function call, and multiply it by 10 and add current root value to it, and loop to the leaf node like this.
//  When a recursion reaches a leaf node, we record the current value and sum all leaf node values as a result.
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
    void solve(TreeNode* root, int num, int& sum) {
        if (!root)
        {
            return;
        }
        num = num * 10 + root->val;
        if (!root->left && !root->right)
        {
            sum += num;
        }
        solve(root->left, num, sum);
        solve(root->right, num, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
};