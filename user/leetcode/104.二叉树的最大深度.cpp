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
        return (max(maxDepth(root->left), maxDepth(root->right)) + 1);

        if(root == nullptr) return 0;
        int count, ans = 0;
        queue<TreeNode*> que;
        TreeNode* q;
        que.push(root);
        while(!que.empty())
        {
            count = que.size();
            while(count)
            {
                count--;
                q = que.front(); que.pop();
                if(q->left != nullptr)  que.push(q->left);
                if(q->right != nullptr) que.push(q->right);
            }
            ans++;
        }
        return ans;
    }
};