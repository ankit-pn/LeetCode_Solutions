class Solution {
public:
   int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
       for(int i=1;i<m-1;i++){
           for(int j=1;j<n-1;j++){
               bool check=true;
               int val=0;
               if(grid[i][j]==1){
                   dfs(grid,i,j,check,val);
                   if(check)
                       ans+=val;
               }
           }
       } 
        return ans;
    }
    void dfs(vector<vector<int>> &grid,int sr,int sc,bool &check,int &val){
        int m=grid.size();
        int n=grid[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || grid[sr][sc]!=1)
            return ;
        if(sr==0 || sc==0 || sr==m-1 || sc == n-1)
            check=false;
        grid[sr][sc]=-1;
        val++;
        dfs(grid,sr-1,sc,check,val);
        dfs(grid,sr+1,sc,check,val);
        dfs(grid,sr,sc-1,check,val);
        dfs(grid,sr,sc+1,check,val);
        
    }
};