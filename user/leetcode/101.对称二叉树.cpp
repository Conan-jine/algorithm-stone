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
    bool check(TreeNode* l, TreeNode* r)
    {
        // 都是空节点
        if(l == nullptr && r == nullptr) return true;
        // 一边是空节点
        else if( !(l&& r) )  return false;
        else    return (l->val == r->val) && check(l->left, r->right) && check(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        queue<TreeNode*> que;
        TreeNode* u;
        TreeNode* v;
        u = root;
        v = root;
        que.push(u);
        que.push(v);
        while(!que.empty())
        {
            u = que.front(); que.pop();
            v = que.front(); que.pop();
            if(u == nullptr && v == nullptr)    continue;
            if( !(u && v) || u->val != v->val) return false;
            que.push(u->left);
            que.push(v->right);
            que.push(u->right);
            que.push(v->left);
        }
        return true;
    }
};