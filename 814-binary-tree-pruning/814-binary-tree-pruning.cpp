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
    unordered_map<TreeNode*,int> cont;
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return root;
        if(isContain(root)){
            auto x1= pruneTree(root->left);
            auto x2=pruneTree(root->right);
            root->left=x1;
            root->right=x2;
            return root;
        }
        else{
            return NULL;
        }
    }
    bool isContain(TreeNode* root){
        if(!root)
            return 0;
        if(cont.find(root)!=cont.end()){
            return cont[root]==1 ? 1: 0;
        }
        if(root->val==1)
            return 1;
        cont[root] = (isContain(root->left) || isContain(root->right)) ? 1 : 2;
        return cont[root]==1;
    }
};