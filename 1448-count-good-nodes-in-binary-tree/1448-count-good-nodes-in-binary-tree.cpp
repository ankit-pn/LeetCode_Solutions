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
    int goodNodes(TreeNode* root) {
         if(!root)
            return 0;
        int c=1;
        if(root->left && root->left->val<root->val){
            root->left->val=root->val;
            c--;
        }
        c+=goodNodes(root->left);
        if(root->right && root->right->val<root->val){
            root->right->val=root->val;
            c--;
        }
        c+=goodNodes(root->right);
        return c;
    }
};