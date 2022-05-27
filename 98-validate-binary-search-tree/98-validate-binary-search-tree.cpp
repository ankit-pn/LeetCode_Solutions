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
    long long ans=-1e18;
    int f=1;
    bool isValidBST(TreeNode* root) {
       inorder(root);
        return f;
        
        // if(!root)
        //     return 1;
        // int f=1;
        // if(root->left && root->left->val>=root->val)
        //     f=0;
        // if(root->right && root->right->val<=root->val)
        //     f=0;
        // return f && isValidBST(root->left) && isValidBST(root->right);
       // stack<TreeNode*> s;
       //  TreeNode* prev=NULL;
       //  while(root!=NULL || !s.empty()){
       //      while(root!=NULL){
       //          s.push(root);
       //          root=root->left;
       //      }
       //      root=s.top();
       //      s.pop();
       //      if(prev!=NULL && prev->val>=root->val)
       //          return 0;
       //      prev=root;
       //      root=root->right;
       //  }
       //  return 1;
    }
    void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->left);
        if(root->val<=ans){
            f=0;
            return ;
        }
        else{
            ans=root->val;
        }
        inorder(root->right);
    }
};