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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        dfs(root1,res1);
        dfs(root2,res2);
        return res1==res2;
    }
    void dfs(TreeNode* root,vector<int> &res){
        if(!root)
            return ;
        if(!(root->left) and !(root->right))
            res.push_back(root->val);
        dfs(root->left,res);
        dfs(root->right,res);
    }
    
};