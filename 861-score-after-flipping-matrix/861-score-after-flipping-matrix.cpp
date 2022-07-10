class Solution {
public:
    void flipcol(vector<vector<int>>&g,int c){
        for(int i=0;i<g.size();i++){
            g[i][c] = (g[i][c]==1)?0:1;
        }
    }
    void fliprow(vector<vector<int>> &g,int r){
        for(int i=0;i<g[r].size();i++){
            g[r][i] = (g[r][i]==1)?0:1;
        }
    }
    int provid_binary(vector<vector<int>>&grid , int r){
        int n=grid[r].size();
        int i=0,ans=0;
        while(i<n){
            ans+=pow(2,i)*grid[r][n-i-1];
            i++;
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)
                fliprow(grid,i);
        }
       
            for(int j=1;j<m;j++){
                  int c=0,o=0;
              for(int i=0;i<n;i++){
                
                  if(grid[i][j]==1)
                      c++;
                  else
                      o++;
              }
                if(o>c)
                    flipcol(grid,j);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=provid_binary(grid,i);
        }
        return ans;
        
        
        
    }
};