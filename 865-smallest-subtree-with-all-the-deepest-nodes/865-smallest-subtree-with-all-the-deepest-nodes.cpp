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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
            return root;
        auto l1=lowestCommonAncestor(root->left,p,q);
         auto l2=lowestCommonAncestor(root->right,p,q);
        if(l2==NULL)
            return l1;
        else if(l1==NULL)
            return l2;
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
        lowestCommonAncestor(root,ans[0],ans[1]);
    }
};