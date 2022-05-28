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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> res;
        inorder(root,res);
        return cons(res,0,res.size()-1);
    }
    void inorder(TreeNode* root,vector<TreeNode*> &res){
        if(!root)
            return ;
        inorder(root->left,res);
        res.push_back(root);
        inorder(root->right,res);
    }
    TreeNode* cons(vector<TreeNode*> &res,int i,int j){
        if(i>j)
            return NULL;
        int k=(i+j)/2;
        res[k]->left=cons(res,i,k-1);
        res[k]->right=cons(res,k+1,j);
        return res[k];
    }
};