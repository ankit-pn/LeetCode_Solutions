class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> g(n);
        vector<int> ans(n,-1);
        for(int i=0;i<richer.size();i++){
            g[richer[i][1]].push_back(richer[i][0]);
        }  
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            if(!v[i])
         dfs(g,quiet,ans,i,v);
        return ans;
    }
    unordered_map<int,pair<int,int>> mp;
    pair<int,int> dfs(vector<vector<int>> &g,vector<int> &qui,vector<int> &ans,int in,vector<int> &v){
        v[in]=1;
        if(mp.find(in)!=mp.end())
            return mp[in];
        pair<int,int> te={qui[in],in};
        for(auto &it:g[in]){
            auto x=dfs(g,qui,ans,it,v);
            if(x.first<te.first){
                te=x;
            }
        }    
        mp[in]=te;
        ans[in]=te.second;
        return te;
    }
};