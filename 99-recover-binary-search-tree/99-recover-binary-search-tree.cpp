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
    // well this has three variable soln.
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* f=NULL;
    TreeNode* s=NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        // once we get all these three node, all we need is to swap their value
        // to recover this binary tree.
        if(f && s){
        int temp=f->val;
        f->val=s->val;
        s->val=temp;
        }
    }
    void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->left);
        // well first time i have to find larger element nd second time i have to find smaller element.
        // thats all we need , hence once we get prev nd second time root.
        // well remove = from prev->val>=root->val in both of cases.
        if(!f && prev->val>root->val)
            f=prev;
        // you have used eles if , i mean why.
        if(f && prev->val>root->val)
            s=root;
        prev=root;
        inorder(root->right);
    }
};