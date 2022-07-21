class Solution {
public:
    bool containsCycle(vector<vector<char>>& g) {
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]!='V')
                    if(bfs(g,i,j))
                        return true;
            }
        }
        return false;
    }
    bool bfs(vector<vector<char>>&g,int i,int j){
        int n=g.size(),m=g[0].size();
        vector<vector<int>> d={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto it=q.front();
            char curr=g[it.first][it.second];
            if(curr=='V')
                return true;
            g[it.first][it.second]='V';
            q.pop();
            for(int k=0;k<4;k++){
                int in=it.first+d[k][0];
                int jn=it.second+d[k][1];
                if(in>=0 && in<n && jn>=0 && jn<m){
                    if(g[in][jn]==curr)
                        q.push({in,jn});
                }
            }
        }
        return false;
    }
};