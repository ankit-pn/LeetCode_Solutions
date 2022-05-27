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
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(arr,root);
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]+arr[j]==k)
                return 1;
            else if(arr[i]+arr[j]>k)
                j--;
            else
                i++;
        }
        return 0;
    }
    void inorder(vector<int> &ans,TreeNode* root){
        if(!root)
            return ;
        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
};