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
     bool iss1(vector<int> &arr){
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<=arr[i+1])
                return 0;
        }
        return 1;
    }
    bool iss(vector<int> &arr){
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>=arr[i+1])
                return 0;
        }
        return 1;
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode* > qu;
        qu.push(root);
        int c=0;
        while(!qu.empty()){
            int n=qu.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                auto it=qu.front();
                if(it->left)
                qu.push(it->left);
                if(it->right)
                qu.push(it->right);
                qu.pop();
                if(c%2==0 && it->val%2==0)
                    return 0;
                else if(c%2==1 && it->val%2==1)
                    return 0;
                else
                    temp.push_back(it->val);
            }
           
            if(c%2==0 && !iss(temp))
                return 0;
            if(c%2==1 && !iss1(temp))
                return 0;
                 c++;
        }
        return 1;
    }
};