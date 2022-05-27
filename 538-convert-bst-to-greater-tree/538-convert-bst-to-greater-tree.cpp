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
    TreeNode* convertBST(TreeNode* root) {
       inorder(root);
        return root;
    }
    int sum=0;
    void inorder(TreeNode* root){
        if(!root)
            return ;
        convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        convertBST(root->left);
    }
};