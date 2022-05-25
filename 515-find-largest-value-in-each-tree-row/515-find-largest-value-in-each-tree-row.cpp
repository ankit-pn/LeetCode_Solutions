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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> qu;
        vector<int> ans;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            int mx=INT_MIN;
        for(int i=0;i<n;i++){
            auto it=qu.front();
            if(it->left)
            qu.push(it->left);
            if(it->right)
            qu.push(it->right);
            qu.pop();
            mx=max(mx,it->val);
        }
            ans.push_back(mx);
        }
        return ans;
    }
};