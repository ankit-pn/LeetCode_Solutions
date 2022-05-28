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
    set<int> st;
    vector<TreeNode* > res;
    // bool f=1;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto it:to_delete)
            st.insert(it);
        dfs(root);
        if(root)
        res.push_back(root);
        return res;
    }
//     TreeNode* dfs(TreeNode* root,bool f){
//         // if(!root)
//         //     return root;
//         //     bool x= st.find(root->val)!=st.end();
//         // if(f && !x){
//         //     res.push_back(root);
//         // }
//         //  // f=x;
//         // root->left=dfs(root->left,x);
//         // root->right=dfs(root->right,x);
//         // if(x)
//         //     return NULL;
//         // else
//         //     return root;
        
        
//     }
    void dfs(TreeNode* &root){
        if(!root)
            return ;
        dfs(root->left);
        dfs(root->right);
        if(st.find(root->val)!=st.end()){
            if(root->left)
            res.push_back(root->left);
            if(root->right)
            res.push_back(root->right);
            root=NULL;
            delete root;
        }
    }
};