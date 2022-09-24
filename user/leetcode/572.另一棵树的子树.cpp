/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

// @lc code=start
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

    bool judge(TreeNode *root, TreeNode *subRoot)
    {
        if(root == nullptr && subRoot == root)  return true;
        if( !root && subRoot || root && !subRoot)    return false;
        if(root->val != subRoot->val)   return false;
        return judge(root->left, subRoot->left) && judge(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if(root == nullptr) return false;
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return judge(root, subRoot) || left || right;
    }
};
// @lc code=end
