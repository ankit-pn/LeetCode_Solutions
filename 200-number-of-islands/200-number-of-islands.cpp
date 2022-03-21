class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
          int m=grid.size();
        int n=grid[0].size();
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    c++;
                    dfs(grid,i,j);
                }
            }
        }
        return c;
    }
    void dfs(vector<vector<char>>& grid,int sr,int sc){
        int m=grid.size();
        int n=grid[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || grid[sr][sc]!='1')
            return ;
        grid[sr][sc]='t';
        dfs(grid,sr-1,sc);
        dfs(grid,sr+1,sc);
        dfs(grid,sr,sc-1);
        dfs(grid,sr,sc+1);
    }
};