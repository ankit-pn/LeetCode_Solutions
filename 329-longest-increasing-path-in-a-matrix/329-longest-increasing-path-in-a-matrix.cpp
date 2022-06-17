class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& arr) {
        // same code as lis
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x= dfs(arr,dp,i,j,n,m);
                ans = max(ans,x);
            }
        }
        return ans;
        
    }
    int dfs(vector<vector<int>>& arr,vector<vector<int>>& dp,int i,int j,int n,int m){
        if(dp[i][j]!=0)
            return dp[i][j];
        int mi=1,a=0,b=0,c=0,d=0;
        if(i+1<n && arr[i][j]>arr[i+1][j])
        a = dfs(arr,dp,i+1,j,n,m);
        if(i>0 && arr[i][j]>arr[i-1][j])
        b = dfs(arr,dp,i-1,j,n,m);
        if(j+1<m && arr[i][j]>arr[i][j+1])
        c = dfs(arr,dp,i,j+1,n,m);
        if(j>0 && arr[i][j]>arr[i][j-1])
        d = dfs(arr,dp,i,j-1,n,m);
        int x = max({a,b,c,d});
        int ans=x+1;
        dp[i][j]=ans;
        return ans;
    }
};