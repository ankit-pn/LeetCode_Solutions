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
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return ans;
        
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(l<0)
            l=0;
        if(r<0)
            r=0;
        int temp=max(max(l,r)+root->val,root->val);
        int temp1=max(l+r+root->val,temp);
        ans=max(ans,temp1);
        return temp;
    }
};