/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode *root)
    {
        if(root == nullptr) return "";
        string res = "";
        res += to_string(root->val);
        string left = tree2str(root->left);
        string right = tree2str(root->right);
        if(root->left != nullptr && root->right == nullptr)   res += "("+left+")";
        if(root->right != nullptr && root->left == nullptr)   res += "()("+right+")";
        if(root->left != nullptr && root->right != nullptr) res += "("+left+")("+right+")";
        return  res;
    }
};
// @lc code=end
