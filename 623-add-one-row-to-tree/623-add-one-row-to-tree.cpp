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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> qu;
        qu.push(root);
        int target=depth-1;
        int c=1;
        int f=0;
        if(target==0){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                auto it=qu.front();
                qu.pop();
                if(c==target){
                    TreeNode* in=new TreeNode(val);
                    TreeNode* temp=it->left;
                    it->left=in;
                    in->left=temp;
                    TreeNode* in1=new TreeNode(val);
                    TreeNode* temp2=it->right;
                    it->right=in1;
                    in1->right=temp2;
                }
                else{
                    if(it->left)
                        qu.push(it->left);
                    if(it->right)
                        qu.push(it->right);
                }
               
            }
            if(f)
                break;
             c++;
        }
        return root;
    }
};