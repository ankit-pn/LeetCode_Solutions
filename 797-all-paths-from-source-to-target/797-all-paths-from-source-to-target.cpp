class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        vector<int> v(n,0);
        dfs(g,temp,ans,v,0);
        return ans;
    }
    void dfs(vector<vector<int>>& g,vector<int> &temp,vector<vector<int>> &ans,vector<int>&v,int in){
        // if(v[in])
        //     return ;
        // v[in]=1;
        // there is no need of backtracking if it is directed.
        if(in==g.size()-1){
            ans.push_back(temp);
             return ;
        }
        for(auto it:g[in]){
        temp.push_back(it);
            dfs(g,temp,ans,v,it);
            temp.pop_back();
        }
    }
};