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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
        if(root->val%2)
            return sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
        else{
            int x=0;
            if(root->left && root->left->left)
                x+=root->left->left->val;
             if(root->left && root->left->right)
                x+=root->left->right->val;
            if(root->right && root->right->left)
                x+=root->right->left->val;
             if(root->right && root->right->right)
                x+=root->right->right->val;
             return sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right)+x;
        }
    }
};