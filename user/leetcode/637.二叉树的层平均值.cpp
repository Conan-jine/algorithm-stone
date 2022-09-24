/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        double len;
        long sum = 0;
        TreeNode* temp;
        vector<double> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            len = que.size();
            sum = 0;
            for(int i=0; i<len; i++)
            {
                temp = que.front();
                que.pop();
                sum += temp->val;
                if(temp->left != nullptr)   que.push(temp->left);
                if(temp->right != nullptr)  que.push(temp->right);
            }
            res.push_back(sum / len);
        }
        return res;
    }
};
// @lc code=end
