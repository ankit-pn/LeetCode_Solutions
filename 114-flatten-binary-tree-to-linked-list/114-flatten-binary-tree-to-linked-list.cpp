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
    void flatten(TreeNode* root) {
        root = help(root);   
    }
    TreeNode* help(TreeNode* root){
        if(!root)
            return root;
       auto it1=help(root->left);
        auto it2=help(root->right);
        root->right=it1;
        root->left=NULL;
        auto temp=root;
        while(temp->right){
            temp=temp->right;
        }
        temp->right=it2;
        return root;
    }
};