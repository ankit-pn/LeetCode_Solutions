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
    map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        // another question with simple bfs traversal
        
        // if(!root)
        //     return 0;
        // int l1=0,l2=0,f=0;
        // queue<TreeNode*> qu;
        // qu.push(root);
        // while(!qu.empty()){
        //     int n=qu.size();
        //     for(int i=0;i<n;i++){
        //         auto it=qu.front();
        //         if(it->left)
        //             qu.push(it->left);
        //         if(it->right)
        //             qu.push(it->right);
        //         if(!f)
        //             l1+=it->val; 
        //         else
        //             l2+=it->val;
        //         qu.pop();
        //     }
        //     if(!f)
        //     f=1;
        //     else
        //     f=0;
        // }
        // return max(l1,l2);
        
        // well this simple bfs traversal is not working, hence working on b\dfs traversal
        
        if(!root)
            return 0;
        int x=root->val;
        if(root->left){
            if(mp.find(root->left->left)!=mp.end()){
            x+=mp[root->left->left];
            }
            else{
                  mp[root->left->left]=rob(root->left->left);
                 x+=mp[root->left->left];
            }
            
            if(mp.find(root->left->right)!=mp.end()){
            x+=mp[root->left->right];
            }
            else{
                  mp[root->left->right]=rob(root->left->right);
                 x+=mp[root->left->right];
            }
        }
         if(root->right){
             if(mp.find(root->right->left)!=mp.end()){
            x+=mp[root->right->left];
            }
            else{
                  mp[root->right->left]=rob(root->right->left);
                 x+=mp[root->right->left];
            }
            
            if(mp.find(root->right->right)!=mp.end()){
            x+=mp[root->right->right];
            }
            else{
                  mp[root->right->right]=rob(root->right->right);
                 x+=mp[root->right->right];
            }
         }

            return max(rob(root->left)+rob(root->right),x);
        
        
        
        
    }
};