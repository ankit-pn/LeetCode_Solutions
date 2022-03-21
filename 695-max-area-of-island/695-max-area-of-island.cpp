class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(grid,i,j,area);
                    ans=max(area,ans);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int sr,int sc,int &area){
        int m=grid.size();
        int n=grid[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || grid[sr][sc]!=1)
            return ;
        grid[sr][sc]=-1;
        area+=1;
        dfs(grid,sr-1,sc,area);
        dfs(grid,sr+1,sc,area);
        dfs(grid,sr,sc-1,area);
        dfs(grid,sr,sc+1,area);
        
        return;
        
    }
};