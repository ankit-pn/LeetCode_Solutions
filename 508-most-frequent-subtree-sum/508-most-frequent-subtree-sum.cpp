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
    unordered_map<TreeNode*,int> ss; 
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int x=sum(root);
        map<int,int> temp;
        for(auto it:ss){
            temp[it.second]++;
        }
        int mx=0;
        int su=0;
        for(auto it:temp){
            if(it.second>mx)
            {
           mx=it.second;
                su=it.first;
        }
    }
    vector<int> ans;
        for(auto it:temp){
            if(it.second==mx){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
    int sum(TreeNode* root){
        if(!root)
            return 0;
        ss[root] = root->val+sum(root->left)+sum(root->right);
        return ss[root];
    }
};