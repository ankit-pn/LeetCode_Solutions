/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!target || !original)
            return cloned;
        if(original==target)
            return cloned;
        TreeNode* t1= getTargetCopy(original->left,cloned->left,target);
        TreeNode* t2= getTargetCopy(original->right,cloned->right,target);
        if(t1)
            return t1;
        else
            return t2;
    }
};