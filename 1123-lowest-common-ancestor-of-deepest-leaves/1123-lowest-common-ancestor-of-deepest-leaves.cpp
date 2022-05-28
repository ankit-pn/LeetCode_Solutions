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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode* > qu;
        qu.push(root);
        vector<TreeNode*> ans(2);
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                auto it=qu.front();
                qu.pop();
                if(it->left)
                    qu.push(it->left);
                if(it->right)
                    qu.push(it->right);
                if(i==0)
                    ans[0]=it;
                if(i==n-1)
                    ans[1]=it;
            }
        }
        if(ans[0]==ans[1])
            return ans[1];
        else
            return lca(root,ans[0],ans[1]);
    }
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root || root==p || root==q)
            return root;
        auto l1=lca(root->left,p,q);
        auto l2=lca(root->right,p,q);
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        else
            return root;
    }
};