// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,vector<vector<char>>& grid ,vector<vector<int>> &arr)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return;
        if(arr[i][j]==1 or grid[i][j]=='0') return;
        
        arr[i][j]=1;
        dfs(i+1,j,grid,arr);
        dfs(i-1,j,grid,arr);
        dfs(i,j+1,grid,arr);
        dfs(i,j-1,grid,arr);
        dfs(i+1,j+1,grid,arr);
        dfs(i-1,j-1,grid,arr);
        dfs(i+1,j-1,grid,arr);
        dfs(i-1,j+1,grid,arr);
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> arr(n+1,vector<int>(m+1,0));
        int cou=0; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and arr[i][j]!=1)
                {
                    cou++;
                    dfs(i,j,grid,arr);
                }
            }
        }
        
        
        return cou;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends