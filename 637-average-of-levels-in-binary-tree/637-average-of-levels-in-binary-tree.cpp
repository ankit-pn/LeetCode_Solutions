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
    vector<double> averageOfLevels(TreeNode* root) {
          if(!root)
            return {};
        queue<TreeNode*> qu;
        vector<double> ans;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            long long sum=0;
            int c=0;
        for(int i=0;i<n;i++){
            auto it=qu.front();
            if(it->left)
            qu.push(it->left);
            if(it->right)
            qu.push(it->right);
             sum+=it->val;
            c++;
            qu.pop();
          
        }
            ans.push_back(sum/(double)c);
        }
        return ans;
    }
};