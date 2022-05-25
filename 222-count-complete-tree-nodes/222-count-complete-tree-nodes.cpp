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
    int countNodes(TreeNode* root) {
        // here we go , another recursive soln of another problem
        // calculating height of left side
        if(!root)
            return 0;
            
        
        TreeNode* left=root,*right=root;
        int cl=0,cr=0;
        while(left){
            left=left->left;
            cl++;
        }
        while(right){
            right=right->right;
            cr++;
        }
        
        if(cl==cr){
            return (1<<cr)-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
        
    }

};