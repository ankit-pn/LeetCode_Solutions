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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int t=0;
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                auto it=qu.front();
                if(it->left)
                    qu.push(it->left);
                if(it->right)
                    qu.push(it->right);
                if(i==0){
                    t=it->val;
                }
                qu.pop();
            }
        }
        return t;
    }
};