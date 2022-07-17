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
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // stack<TreeNode *> s;
        // while(root!=NULL  || !s.empty()){
        //     while(root!=NULL){
        //         s.push(root);
        //         root=root->left;
        //     }
        //     root=s.top();
        //     s.pop();
        //     ans.push_back(root->val);
        //     root=root->right;
        // }
        // return ans;
        
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root=st.top();
            ans.push_back(root->val);
            st.pop();
            root=root->right;
        }
        return ans;
    }
};