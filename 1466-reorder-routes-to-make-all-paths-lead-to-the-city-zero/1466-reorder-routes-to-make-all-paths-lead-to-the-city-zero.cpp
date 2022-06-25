class Solution {
public:
    int minReorder(int n, vector<vector<int>>& cn) {
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<cn.size();i++){
            int a=cn[i][0];
            int b=cn[i][1];
            g[a].push_back({b,1});
            g[b].push_back({a,-1});
        }
        vector<int> v(n,0);
        return dfs(g,v,0); 
    }
    int dfs(vector<vector<pair<int,int>>> &g,vector<int> &v,int in){
        if(v[in])
            return 0;
        v[in]=1;
        int ans=0;
        // well mistake is here 
        for(auto &it:g[in]){
            // - down line , you have to check for visisted before second one also.......
             if(!v[it.first]){
            if(it.second==1)
                ans+=1;
            ans+=dfs(g,v,it.first);
             }
        }
        return ans;
    }
};