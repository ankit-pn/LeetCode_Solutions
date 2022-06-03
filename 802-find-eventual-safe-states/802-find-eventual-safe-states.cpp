class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dfs(graph,i,v))
                ans.push_back(i);
        }
        return ans;
        
        
        
        }
    bool dfs(vector<vector<int>>& graph,int i,vector<int> &v){
        if(v[i]==1)
            return false;
        if(v[i]==-1)
            return true;
        v[i]=1;
        for(int j=0;j<graph[i].size();j++){
            if(!dfs(graph,graph[i][j],v))
                return false;
        }
        v[i]=-1;
        return true;
        
    }




};