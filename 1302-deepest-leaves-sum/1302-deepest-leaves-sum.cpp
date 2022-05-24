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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int sum=0;
        while(!qu.empty()){
            int len=qu.size();
            sum=0;
            for(int i=0;i<len;i++){
                auto it=qu.front();
                if(it->left)
                    qu.push(it->left);
                if(it->right)
                    qu.push(it->right);
                sum+=it->val;
                qu.pop();
            }
        }
        return sum;
    }
};