/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

    int getMaxLeft(TreeNode *root)
    {
        if(root == nullptr) return 0;
        return max(getMaxLeft(root->right), root->val);
    }

    int getMinRight(TreeNode *root)
    {
        if(root == nullptr) return 1e5 + 1;
        return min(getMinRight(root->left), root->val);
    }

    int getMinimumDifference(TreeNode *root)
    {
        if(root == nullptr) return 1e5 + 1;
        int minNum = 1e5;
        if(root->left != nullptr)
        {
            minNum = min(getMinimumDifference(root->left), root->val - getMaxLeft(root->left));
        }
        if(root->right != nullptr)
        {
            minNum = min(minNum, getMinRight(root->right) - root->val);
            minNum = min(minNum, getMinimumDifference(root->right));
        }
        return minNum;
    }
};
// @lc code=end
