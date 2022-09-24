/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int ans = 0;

    int count(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftNum = count(root->left);
        int rightNum = count(root->right);
        ans += abs(leftNum - rightNum);
        return root->val + leftNum + rightNum;
    }

    int findTilt(TreeNode *root)
    {
        count(root);
        return ans;
    }
};
// @lc code=end
