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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root || p==root || q==root)
           return root;
        auto it=lca(root->left,p,q);
        auto it1=lca(root->right,p,q);
        if(!it)
            return it1;
        if(!it1)
            return it;
        else
            return root;
            
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> ans(2);
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                auto it=qu.front();
                if(it->left)
                    qu.push(it->left);
                if(it->right)
                    qu.push(it->right);
                if(i==0)
                    ans[0]=it;
                if(i==n-1)
                    ans[1]=it;
                qu.pop();
            }
        }
        return 
        lca(root,ans[0],ans[1]);
    }
};