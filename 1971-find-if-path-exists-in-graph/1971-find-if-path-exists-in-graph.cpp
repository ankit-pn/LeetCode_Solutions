class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int end) {
        vector<vector<int>> g(n);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> v(n,0);
        return dfs(g,source,end,v);
    }
    bool dfs(vector<vector<int>> &g,int source,int end,vector<int> &v){
        if(v[source])
            return 0;
        v[source]=1;
        if(source==end)
            return 1;
        bool ans=0;
        for(auto it:g[source]){
            ans|=dfs(g,it,end,v);
        }
        return ans;
    }
};