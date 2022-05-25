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
    bool isCompleteTree(TreeNode* root) {
        // there should be no node , after we met empty node in case of Complete tree.
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
        for(int i=0;i<n;i++){
            auto it=qu.front();
             if(!it){
                while(!qu.empty()){
                    auto t=qu.front();
                    if(t)
                        return 0;
                    qu.pop();
                }
                 return 1;
             }
            qu.push(it->left);
            qu.push(it->right);
            qu.pop();
        }
            }
        return 1;
    }
};