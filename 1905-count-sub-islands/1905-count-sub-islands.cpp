class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int m=grid1.size();
        int n=grid1[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                bool check=true;
                dfs(grid1,grid2,i,j,check);
                if(check)
                    ans++;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int sr,int sc,bool &check){
        int m=grid1.size();
        int n=grid1[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || grid2[sr][sc]!=1){
            return ;
        }
        if(grid2[sr][sc]==1 && grid1[sr][sc]==0)
            check=false;
        grid2[sr][sc]=-1;
        grid1[sr][sc]=-1;
        
          dfs(grid1,grid2,sr+1,sc,check);
          dfs(grid1,grid2,sr-1,sc,check);
          dfs(grid1,grid2,sr,sc+1,check);
          dfs(grid1,grid2,sr,sc-1,check);
    }
};