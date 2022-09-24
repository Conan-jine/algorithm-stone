/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
class Solution {
public:

    int ans = -1;
    int rootNum;

    void dfs(TreeNode* root)
    {
        if(root == nullptr) return;
        if(root->val > ans && ans != -1)    return;
        if(root->val > rootNum)    ans = root->val;
        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root)
    {
        rootNum = root->val;
        dfs(root);
        if(root->val == ans)    return -1;
        return ans;
    }
};
// @lc code=end

