class Solution {
public:
    vector<int> res;
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
      int m=arr.size();
        vector<int> g[n];
        for(int i=0;i<m;i++){
            g[arr[i][0]].push_back(arr[i][1]);
        }
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(!dfs(g,v,n,i))
                return {};
        }
        return res;
    }
    bool dfs(vector<int> g[],vector<int> &v,int n,int i){
        if(v[i]==1)
            return false;
        if(v[i]==-1)
            return true;
        v[i]=1;
        for(int k=0;k<g[i].size();k++){
            if(!dfs(g,v,n,g[i][k]))
                return 0;
        }
        if(v[i]!=-1)
        res.push_back(i);
        v[i]=-1;
        return true;
    }
};