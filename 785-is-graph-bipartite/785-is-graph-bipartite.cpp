class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                bool temp=bfs(g,color,i);
                if(!temp){
                    return temp;
                }
            }
        }
        return 1;
        
    }
    bool bfs(vector<vector<int>>& g,vector<int> &color,int in){
         queue<int> qu;
            qu.push(in);
        color[0]=1;
        bool f=0;
        while(!qu.empty()){
            auto it1=qu.front();
            qu.pop();
            int req=(color[it1]==1)?2:1;
            for(auto it:g[it1]){
                if(color[it]!=0 && color[it]!=req){
                    f=1;
                    break;
                }
                else if(color[it]==0){
                    color[it]=req;
                qu.push(it);
                }
            }
            if(f)
                break;
        }
        
        return !f;
    }
};