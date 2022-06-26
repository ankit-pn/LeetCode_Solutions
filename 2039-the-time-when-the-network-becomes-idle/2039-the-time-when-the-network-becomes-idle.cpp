class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pt) {
        // calcuating distance.....
        int n=pt.size();
        vector<int> dist(n);
        vector<vector<int>> g(n);
        for(auto &it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> v(n,0);
        bfs(g,dist,v);
        int ans=-1;
        for(int i=0;i<n;i++)
            cout<<dist[i]<<" ";
        // well expected your formula is not correct.
        // may be your formula is correct.......
         for(int i=1;i<n;i++){
             int k=(2*dist[i])%pt[i];
             if(k==0)
                 k=pt[i];
            int p11=4*dist[i]-k+1;
            if(p11<0)
                p11=2*dist[i]+1;
            ans=max(ans,p11);
        }
        return ans;
    }
    // int dfs(vector<vector<int>> &g,vector<int> &v,vector<int> &dist,int in){
    //     if(!in)
    //         return 0;
    //     if(dist[in]!=1e6)
    //         return dist[in];
    //     if(v[in])
    //         return dist[in];
    //     v[in]=1;
    //     int m=0;
    //     int x=1e6;
    //     for(auto &it:g[in]){
    //         int y = dfs(g,v,dist,it);
    //         x=min(y,x);
    //     }
    //     dist[in]=x==1e6?1e6:1+x;
    //     return dist[in];
    // }
    
    // dfs sucks , why the fk u r even using it is one of my concern......
    
    void bfs(vector<vector<int>> &g,vector<int> &dist,vector<int> &v){
        queue<int> q;
        q.push(0);
        // int curr=1;
        v[0]=1;
        dist[0]=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto &it:g[x]){
                // finally you got the mistake , you need to put everything under v[it]==0 roof.
                if(v[it]==0){
                dist[it]=dist[x]+1;
                q.push(it);
                v[it]=1;
                }
            }
            // curr++;
        }
    }
};