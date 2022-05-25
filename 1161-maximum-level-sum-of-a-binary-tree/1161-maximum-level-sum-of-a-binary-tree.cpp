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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int c=0;
          int mx=INT_MIN;
        int x=0;
        while(!qu.empty()){
            int n=qu.size();
            int sum=0;
          
            for(int i=0;i<n;i++){
                auto it=qu.front();
                if(it->left)
                    qu.push(it->left);
                if(it->right)
                    qu.push(it->right);
                 sum+=it->val;
                qu.pop();     
            }
            c++;
            if(sum>mx){
                mx=sum;
                x=c;
            }
        }
        return x;
    }
};