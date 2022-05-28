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
    int c=0;
    unordered_map<TreeNode* ,int> mp;
    int averageOfSubtree(TreeNode* root) {
        if(!root)
            return 1;
        int y=sum(root);
        count(root);
        return c;
    }
    int count(TreeNode* root){
        if(!root)
            return 0;
        int x = 1+count(root->left)+count(root->right);
        if((root->val)/x==mp[root]){
        //    cout<<root->val<<"\n";
            c++;
        }
        return x;
    }
    int sum(TreeNode* root){
        if(!root)
            return 0;
        mp[root]=root->val;
        root->val+=(sum(root->left)+sum(root->right));
        return root->val;
    }
};