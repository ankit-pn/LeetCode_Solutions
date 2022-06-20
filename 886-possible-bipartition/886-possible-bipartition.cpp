class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n+1);
        for(auto it:dislikes){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1,0);
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                bool x=bfs(g,color,i);
                if(!x)
                    return x;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>> &g,vector<int> &color,int in){
            queue<int> q;
        q.push(in);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int req=color[it]==1?2:1;
            for(auto it1:g[it]){
                if(color[it1]!=0){
                    if(color[it1]!=req)
                        return false;
                }
                else{
                    color[it1]=req;
                    q.push(it1);
                }
            }
        }
        return true;
    }
};