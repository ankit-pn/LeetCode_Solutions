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
    vector<TreeNode*> generateTrees(int n) {
        // we are going to solve this problem by divide and conqure.
        return help(1,n);
    }
    vector<TreeNode*> help(int start,int end){
        vector<TreeNode*> res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++){
            auto leftSubtree=help(start,i-1);
            auto rightSubtree=help(i+1,end);
            for(auto left:leftSubtree){
                for(auto right:rightSubtree){
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    };