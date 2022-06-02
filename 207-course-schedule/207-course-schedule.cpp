class Solution {
public:
    bool ans=1;
    bool canFinish(int n, vector<vector<int>>&  arr) {
        int m=arr.size();
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            adj[arr[i][0]].push_back(arr[i][1]);
        }
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            if(!dfs(adj,v,n,i))return 0;
        return 1;
    }
    // before submit , anlysing what i hv done
    // baisc cycle detection
    // visit node and mrk visited
    // -1 for completly processed
    // 1 for temp visited
    // it we reached temp processed node
    // again 
    // then return 0
    // otherwise we reach completly processed node
    // then return 
    // re
    bool dfs(vector<int> adj[],vector<int> &v,int n,int i){
            if(v[i]==1)
                return 0;
            if(v[i]==-1)
                return 1;
            v[i]=1;
            for(int j=0;j<adj[i].size();j++)
                if(!dfs(adj,v,n,adj[i][j]))return 0;

            v[i]=-1;
            return 1;
}
};