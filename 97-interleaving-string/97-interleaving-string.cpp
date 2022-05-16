class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length();
        if(n+m!=s3.length())
            return 0;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0)
                    dp[i][j]=1;
                else{
                    if(i-1>=0 && dp[i-1][j] && s2[i-1]==s3[i+j-1])
                    dp[i][j]=1;
                    else if(j-1>=0 && dp[i][j-1] && s1[j-1]==s3[i+j-1])
                        dp[i][j]=1;
                }
            }
        }
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //         }
        //         cout<<"\n";
        // }
        return dp[m][n];
    }
};