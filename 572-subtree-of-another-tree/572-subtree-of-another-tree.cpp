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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return 1;
       else if((root && !subRoot) or (!root && subRoot))
            return 0;
       if(isSame(root,subRoot))
           return 1;
        else
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool isSame(TreeNode* a,TreeNode* b){
        if(!a && !b)
            return 1;
        else if((a && !b) or (!a && b) or (a->val != b->val))
            return 0;
        else
            return isSame(a->left,b->left) and isSame(a->right,b->right);
    }
};