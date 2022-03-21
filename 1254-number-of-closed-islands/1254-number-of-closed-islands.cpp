class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                bool check=true;
                if(grid[i][j]==0){
                    dfs(grid,i,j,check);
                    if(check)
                    ans++;
                }
                
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &grid,int sr,int sc,bool &check){
        int m=grid.size();
        int n=grid[0].size();
        
        if(sr<0 || sc<0 || sr>=m || sc>=n || grid[sr][sc]!=0){
            return ;
        }
        if(sr==0 || sc==0 || sr==m-1 || sc==n-1 ){
            if(grid[sr][sc]==0)
            check=false;
        }
        grid[sr][sc]=-1;
        
        dfs(grid,sr-1,sc,check);
        dfs(grid,sr+1,sc,check);
        dfs(grid,sr,sc-1,check);
        dfs(grid,sr,sc+1,check);
    }
};