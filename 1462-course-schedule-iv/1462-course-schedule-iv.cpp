class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qu) {
        // it will be floyd algo , there is a topo sort algo also exist, but that will be more complex nd worst time complexity of that algo also be n3 , will discussed it later
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<pre.size();i++)
            dp[pre[i][0]][pre[i][1]]=1;
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        vector<bool> ans(qu.size(),0);
        for(int i=0;i<qu.size();i++){
            ans[i]=dp[qu[i][0]][qu[i][1]]!=INT_MAX;
        }
        return ans;
        
        
    }
};