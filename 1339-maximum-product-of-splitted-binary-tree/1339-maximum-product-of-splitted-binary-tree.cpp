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
    long long ans=0;
    long long mod=1e9+7;
    int maxProduct(TreeNode* root) {
            int source=sum(root);
            dfs(root,source);
            return ans%mod;
    }
    long long sum(TreeNode* root){
        if(!root)
            return 0;
        long long x=0;
        if(root->left)
            x+=sum(root->left);
        if(root->right)
            x+=sum(root->right);
        root->val+=x;
        return root->val;
    }
   void  dfs(TreeNode* root, int source){
        if(!root)
            return ;
        dfs(root->left,source);
        dfs(root->right,source);
       long long  z1=source-(root->val);
       long long z2=root->val;
       long long y=(z1*z2);
        ans = max(ans,y);
    }
};