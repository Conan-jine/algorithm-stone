/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int height(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        if(leftH == -1 || rightH == -1 || abs(leftH - rightH) > 1)   return -1;
        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        return height(root) >= 0;
        if(root == nullptr) return true;
        return (abs(maxDepth(root->right) - maxDepth(root->left)) < 2) && isBalanced(root->right) && isBalanced(root->left);
    }
};