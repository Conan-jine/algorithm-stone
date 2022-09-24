/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    TreeNode* findNum(TreeNode *root, int n)
    {
        if(root == nullptr) return nullptr;
        if(root->val == n)  return root;
        if(root->val < n)   return findNum(root->right, n);
        if(root->val > n)   return findNum(root->left, n);
        return nullptr;
    }
    bool findTarget(TreeNode *root, int k)
    {
        queue<TreeNode*> que;
        TreeNode* temp;
        TreeNode* res;
        que.push(root);
        while(!que.empty())
        {
            temp = que.front();
            que.pop();
            res = findNum(root, k - temp->val);
            if(res != temp && res)  return true;
            if(temp->left != nullptr)   que.push(temp->left);
            if(temp->right != nullptr)  que.push(temp->right);
        }
        return false;
    }
};
// @lc code=end
