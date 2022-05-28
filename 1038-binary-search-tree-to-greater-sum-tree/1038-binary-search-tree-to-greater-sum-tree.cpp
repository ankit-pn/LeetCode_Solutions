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
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
    }
    int sum=0;
    void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->right);
        root->val+=sum;
        sum=root->val;
        inorder(root->left);
    }
};